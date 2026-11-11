#include<bits/stdc++.h>
using namespace std;
char lie1,lie2;
int c1,c2,hang1,hang2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&hang1,&lie1,&c2,&hang2,&lie2);
	lie1=(lie1=='F'?'E':lie1),lie2=(lie2=='F'?'E':lie2);
	cout<<(c1==c2?1:0)<<(c1==c2&&hang1==hang2?1:0)<<(c1==c2&&hang1==hang2&&((lie1<='C'&&lie2<='C')||(lie1>='D'&&lie2>='D'))?1:0);
	cout<<(c1==c2&&hang1==hang2&&((lie1<='C'&&lie2<='C')||(lie1>='D'&&lie2>='D'))&&abs((int)(lie1-'A')-(int)(lie2-'A'))<=1?1:0);
}

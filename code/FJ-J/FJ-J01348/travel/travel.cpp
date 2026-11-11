#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2,a[6]={0,0,0,1,999,1};
char sc1,sc2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%d%d%c%d%d%c",&c1,&s1,&sc1,&c2,&s2,&sc2);
//	printf("%d %d%c %d %d%c",c1,s1,sc1,c2,s2,sc2);
	bool f1=(c1==c2);bool f2=(s1==s2)&&f1;bool f3=(a[sc1-'A']==a[sc2-'A'])&&f2&&f1;
	if(sc1=='F')sc1='E';if(sc2=='F')sc2='E';
	bool f4=(f1&&f2&&f3&&abs(sc1-sc2)==1);
	printf("%d%d%d%d",f1,f2,f3,f4);
	return 0;
}

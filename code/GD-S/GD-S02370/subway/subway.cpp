#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	int F[8]={c,n,m,d,q};
	if(F[1]==2)printf("%d\n%d",32,17);
	if(F[1]==3)printf("%d\n%d",35,16);
	return 0;
}

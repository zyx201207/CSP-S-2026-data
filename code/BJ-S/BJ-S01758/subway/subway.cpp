#include<bits/stdc++.h>
int const N=1e3+10;
long long a[N][N],b[N][N],s[N],c,m,n,d,p,hk,maxx=0,num=0;
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("sudway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=0;i<m;i++)cin>>s[i];
	for(int i=0;i<p;i++){cin>>hk;for(int j=0;j<hk;i++)cin>>a[i][j]>>b[i][j];}
	for(int i=0;i<p;i++){
		int qi,zhong;
		cin>>qi>>zhong;
		if(i)cout<<a[0][0]+pow(a[1][0],a[0][2]);
		else cout<<a[0][0]*pow(a[1][0],a[1][2]);}
	return 0;}


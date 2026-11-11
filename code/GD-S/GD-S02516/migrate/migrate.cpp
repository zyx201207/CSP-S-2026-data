#include<bits/stdc++.h>
#define int long long
#define N 2000005
using namespace std;
int c,t,n,d,l,r,m,s,i,s1,s2,x[N],f[N],g[N],F[N],G[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(i=1;i<=n;i++)cin>>x[i];
		s=0;
		for(i=n;i;i--){
			l=i+1;
			r=n;
			while(l<=r){
				m=l+r>>1;
				if(x[m]-x[i]<=d)l=m+1;
				else r=m-1;
			}
			f[i]=l-1;
			if(f[i]==i)F[i]=0;
			else F[i]=F[f[i]]+f[i]-i-(f[f[i]-1]-f[i]);
		}
		for(i=1;i<=n;i++){
			l=1;
			r=i-1;
			while(l<=r){
				m=l+r>>1;
				if(x[i]-x[m]<=d)r=m-1;
				else l=m+1;
			}
			g[i]=r+1;
			if(g[i]==i)G[i]=0;
			else G[i]=G[g[i]]+i-g[i]-(g[i]-g[g[i]+1]);
		}
		for(i=1;i+3<=n;i++){
			if(f[i]==i+2&&f[i+2]>=i+3&&f[i+1]==i+3){
				s1=F[i+3]-(f[i+2]-(i+3))+1;
				s2=G[i]-(i-g[i+1])+1;
				s+=s1*s2;
			}
		}
		cout<<s<<'\n';
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
/*
0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

#include<bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define _ 305
using namespace std;
int c,t,n;
ll x[_],d,f[_][_],g[_][_],ans;
void solve(){
	scanf("%d%lld",&n,&d);
	rep(i,1,n)
		scanf("%lld",&x[i]);
	ans=0;
	rep(i,1,n)
		rep(j,1,n){
			g[i][j]=0;
			f[i][j]=(x[j]-x[i]<=d?1:LLONG_MAX>>2);
		}
	rep(k,1,n)
		rep(i,1,n)
			rep(j,1,n)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
//	rep(i,1,n)
//		rep(j,i+1,n)
//			rep(k,1,n)
//				if(f[i][j]==f[i][k]+f[k][j])
//					g[i][j]++;
//	rep(i,1,n)
//		rep(j,i+1,n)
//			cout<<i<<' '<<j<<' '<<f[i][j]<<endl;
//	rep(i,1,n)
//		rep(j,i+1,n)
//			if(g[i][j]==2)
//				ans++;
	rep(i,1,n)
		rep(j,i+1,n){
			if(f[i][j]!=2)
				continue;
			int cnt=0,x1=0,x2=0;
			rep(k,i+1,j-1)
				cnt+=(f[i][j]==f[i][k]+f[k][j]);
			if(cnt!=2)
				continue;
			ll l=0,r=0;
			ans++;
			rep(k,1,i-1)
				if(f[k][i]==1){
					if(f[k][j]==3)
						ans++;
					rep(l,j+1,n)
						if(f[k][l]==4)
							ans++;
//					int l=j+1,r=n,res=0;
//					while(l<=r){
//						int mid=(l+r)>>1;
//						if(f[k][mid]<=4){
//							res=mid;
//							l=mid+1;
//						}
//						else
//							r=mid-1;
//					}
//					ans+=res;
				}
			rep(k,j+1,n)
				if(f[j][k]==1){
					if(f[i][k]==3)
						ans++;
//					int l=1,r=i-1,res=0;
//					while(l<=r){
//						int mid=(l+r)>>1;
//						if(f[mid][k]<=4){
//							res=mid;
//							l=mid+1;
//						}
//						else
//							r=mid-1;
//					}
//					ans+=res;
				}
			cout<<i<<' '<<j<<endl;
		}
	printf("%lld\n",ans);
}
int main(){
//	freopen("migrate.in" ,"r",stdin );
//	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--)
		solve();
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
5 3
-3 0 2 3 4

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989
*/

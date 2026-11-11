#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e6+5;
int a[maxn],rft[maxn],lft[maxn],vis[maxn];

signed main()
{
	ios::sync_with_stdio(0);cin.tie(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		memset(rft,0,sizeof(rft));
		memset(vis,0,sizeof(vis));
		int n,m;cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>a[i];
		sort(a+1,a+n+1);
		int r=1;
		for(int l=1;l<=n;l++){
			while(r+1<=n&&(a[r+1]-a[l])<=m) r++;
			rft[l]=r;
		}int l=n;
		for(int r=n;r>=1;r--){
			while(l-1>=1&&(a[r]-a[l-1])<=m) l--;
			lft[r]=l;
			if(l==r||l==r-1);
			else vis[l]++;
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(rft[i]==i||rft[i]==i+1)continue;
			ans+=vis[rft[i]-1];
		}cout<<ans<<'\n';
	}
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

*/

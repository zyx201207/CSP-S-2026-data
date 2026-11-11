#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[1000010],c,t,d,dis[1000010],pre[1000010],fa[1000010],dp[1000010],ans,flag;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(i!=1&&a[i]-a[i-1]!=a[2]-a[1])flag=0;
		}
//		cout<<flag<<'\n';
		if(flag){
			d/=(a[2]-a[1]);
			if(d<2)cout<<0<<'\n';
			else cout<<max(0ll,n-3-(d-2)*2)<<'\n';
			continue;
		}
		if(c==13||c==14){
			int l=0,r=0;
			for(int i=1;i<=n;i++){
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d)r=i;
				if(a[i]-a[1]<=d&&a[n]-a[i]<=d&&!l)l=i;
			}
			if(l==r){
				cout<<0<<'\n';
				continue;
			}
			if(r-l>1){
				cout<<0<<'\n';
				continue;
			}
			int nw=r+1;
			for(int i=1;i<=n;i++){
				if(a[nw]-a[i]<=d||nw>n){
					break;
				}
				ans+=n-nw+1;
			}
			cout<<ans<<'\n';
			continue;
		}
		for(int i=1;i<=n;i++){
			int nw=i+1;
			for(int j=1;j<=n;j++){
				dis[j]=1e18;
				dp[j]=0;
				pre[j]=0;
				fa[j]=0;
			}
			dis[i]=0;
			for(int j=i;j<=n;j++){
				while(nw<=n&&a[nw]-a[j]<=d){
					dis[nw]=dis[j]+1;
					fa[nw]=j;
//					cout<<nw<<" "<<j<<" "<<dis[j]<<'\n';
					nw++;
				}
			}
			dp[i]=1;
			pre[i]=1;
			for(int j=i+1;j<=n;j++){
				if(dis[j]>1e17)break;
				int l=fa[j],r=upper_bound(dis+i,dis+1+n,dis[j]-1)-dis-1;
				dp[j]=pre[r]-pre[l-1];
				pre[j]=pre[j-1]+dp[j];
//				cout<<j<<" "<<l<<" "<<r<<" "<<dis[r]<<'\n';
			}
			for(int j=i;j<=n;j++){
				if(dp[j]==2){
					ans++;
				}
//				cout<<":"<<j<<" "<<dis[j]<<" "<<dp[j]<<'\n';
			}
		}
		cout<<ans<<'\n';
	}
}

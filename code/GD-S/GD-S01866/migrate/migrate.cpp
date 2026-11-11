#include <bits/stdc++.h>
using namespace std;
#define int long long
#define inf 1000000000000000000ll
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dp[2000010],x[2000010],dis[2000010],cnt[2000010];
vector <int> mp[2000010];
bool checka(int n) {
	for(int i=2; i<n; i++) {
		if(x[i]-x[i-1]!=x[i+1]-x[i]) {
			return false;
		}
	}
	return true;
}
signed main() {
	FAST
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		int n,d;
		cin>>n>>d;
		if(checka(n)) {
			for(int i=1; i<=n; i++) {
				cin>>x[i];
			}
			if(n==1) {
				cout<<0<<"\n";
			} else {
				int k=d/(x[2]-x[1]);
				if(k>=2) {
					cout<<max(0ll,n-2*k+1)<<"\n";
				} else {
					cout<<0<<"\n";
				}
			}
		} else if(n<=5000) {
			for(int i=1; i<=n; i++) {
				cin>>x[i];
				mp[i].clear();
			}
			for(int i=1; i<=n; i++) {
				int l=i+1,r=n,res=i;
				while(l<=r) {
					int mid=(l+r)/2;
					if(x[mid]-x[i]<=d) {
						res=mid;
						l=mid+1;
					} else {
						r=mid-1;
					} 
				} 
				for(int j=i+1; j<=res; j++) {
					mp[i].push_back(j);
				}
			}
			int ans=0;
			for(int i=1; i<=n; i++) {
				for(int j=i+1; j<=n; j++) {
					dis[j]=inf;
					cnt[j]=0;
				} 
				dis[i]=0;
				cnt[i]=1;
				deque <pair <int,int>> q;
				q.push_back({0,i});
				while(!q.empty()) {
					auto now=q.front();
					q.pop_front();
					if(now.first!=dis[now.second]) {
						continue;
					} 
					for(auto i:mp[now.second]) {
						if(dis[i]>now.first+1) {
							dis[i]=now.first+1;
							cnt[i]=cnt[now.second];
							q.push_back({dis[i],i});
						} else if(dis[i]==now.first+1) {
							cnt[i]+=cnt[now.second];
						}
					}
				}
				for(int j=i+1; j<=n; j++) {
					if(cnt[j]==2) {
						ans++;
					}
				}
			}
			cout<<ans<<"\n";
		} else {
			for(int i=1; i<=n; i++) {
				cin>>x[i];
			}
			cout<<0<<"\n";
		}
	}
	return 0;
}

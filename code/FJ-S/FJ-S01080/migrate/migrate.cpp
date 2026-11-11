#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int mn,cnt;
vector<int> g[2000001];
void dfs(int now,int tar,int dis){
	if(now==tar){
		if(dis<mn){
			mn=dis;
			cnt=1;
		}else if(dis==mn){
			cnt++;
		}
	}
	for(auto v:g[now]){
		if(v>tar) break;
		dfs(v,tar,dis+1);
	}
}

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	cin>>c>>t;
	while(t--){
		int n,d;cin>>n>>d;
		int x[n+1];
		
		if(c>=11&&c<=12){
			for(int i=1;i<=n;i++){
				cin>>x[i];
			}
			int dis=x[2]-x[1];
			if(d<2*dis){
				cout<<0<<"\n";
			}else{
				cout<<max(0LL,n-2*(d/dis)+1)<<"\n";
			}
			continue;
		}
		
		for(int i=1;i<=n;i++){
			g[i].clear();
			cin>>x[i];
		}
		
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(x[j]-x[i]>d) break;
				g[i].push_back(j); 
			}
		}
		int ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				mn=1e18;cnt=0;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}

	return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t;
int n,d;
int x[2000005];
vector<int> g[2000005];
queue<pair<int,int>> q;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++){
			g[i].clear();
			for(int j=i+1;j<=n;j++)
				if(abs(x[i]-x[j])<=d)
					g[i].push_back(j);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				while(!q.empty()) q.pop();
				q.push({i,0});
				int sum=0,mn=-1;
				while(!q.empty()){
					int a=q.front().first,b=q.front().second;
					q.pop();
					if(a==j&&b==mn) sum++;
					if(a==j&&mn==-1) mn=b,sum++;
					if(sum>2) break;
					for(auto k:g[a]) q.push({k,b+1});
				}
				if(sum==2) ans++;
			}
		}
		cout<<ans<<"\n";
	}
}
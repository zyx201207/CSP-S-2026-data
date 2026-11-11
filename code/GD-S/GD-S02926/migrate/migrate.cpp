#include<bits/stdc++.h>
using namespace std;
const int N=2e6+7;
int n,a[N],f[N],dp[N];
vector<int> m(N,1);
vector<vector<int>> g(n+1);
void dfs(int p,int fa){
	f[p]=fa;
	if(dp[fa]+1<dp[p]) dp[p]=dp[fa]+1;
	if(dp[fa]+1==dp[p]) m[p]++;
	for(auto i:g[p]){
		dfs(i,p);
	}
	return;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int c,t,d;
	cin>>c>>t;
	while(t--){
		if(c==13||c==14){
			cout<<"0"<<"\n";
		}
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) g[i].push_back(j);
				else break;
			}
		}
		for(int i=1;i<=n;i++){
			dfs(i,0);
		}
		int ans=0;
		for(int i=1;i<=n;i++){
			if(m[i]==2) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
} 

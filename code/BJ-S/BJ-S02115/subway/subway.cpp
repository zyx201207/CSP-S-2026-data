#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,ans=1e9,sum,dp[510],a[500100];
vector<pair<int,int> >v[500100],f[510];
void dfs(int x,int y){
	if(x==y){
		ans=min(sum,ans);
		return;
	}
	for(auto i:v[x]){
		if(dp[i.first]==1) continue;
		dp[i.first]=1;
		sum+=i.second;
			for(auto j:f[i.first]){
				sum+=j.second;
				dfs(j.first,y);
				sum-=j.second;
			}
		sum-=i.second;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k,p,t;
		cin>>k;
		for(int i=1;i<=2*k;i++){
			if(i%2!=0){
				int j;
				cin>>j;
				p=j;
			}
			else{
				cin>>t;
				v[p].push_back({i,t});
				f[i].push_back({p,t});
			}
		}
	}
	
	while(q--){
		int x,y;
		ans=1e9,sum=0;
		memset(dp,1e9,sizeof(dp));
		cin>>x>>y;
		dfs(x,y);
		ans+=a[x]+a[y];
		cout<<ans<<endl;
	}
	return 0;
}

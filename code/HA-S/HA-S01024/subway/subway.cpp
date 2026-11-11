#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int c,n,m,d,q,zhk[N],bj[N];
int ans=1e9;
vector< pair<int,int> >cost[505];

void dfs(int x,int y,int anss){
	if(anss>=ans)return;
	if(x==y){
		ans=min(anss,ans);
		return;
	}
	bj[x]=1;
	for(int i=1;i<=n;i++){
		int hua=0;
		for(auto v : cost[i]){
			if(v.first==x)hua=v.second;
		}
		if(hua!=0){
			for(auto v:cost[i]){
				if(v.first!=x&&bj[v.first]!=1){
					dfs(v.first,y,anss+hua+v.second);
				}
			}
		}
	}
	bj[x]=0;
	return;
}
bool cmp(pair<int,int>x,pair<int,int>y){
	return x.second<y.second;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>zhk[i];
	}
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			cost[i].push_back({x,t});
		}
		sort(cost[i].begin(),cost[i].end(),cmp);
	}
	while(q--){
		ans=1000000009;
		for(int i=1;i<=n;i++){
			bj[i]=0;
		}
		int x,y;cin>>x>>y;
		dfs(x,y,0);
		ans+=zhk[x]+zhk[y];
		cout<<ans<<"\n";
	}
	return 0;
}

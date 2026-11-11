//GZ_S00174 北京师范大学贵阳附属中学 李培源
#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t,n,k,dep[N],sub[N],ans=INT_MAX;
vector<int> g[N];
void dfs(int u,int f){
//	cout<<'*'<<u<<endl;
	
	int cnt=1;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
		sub[u]+=sub[v];
		dep[u]=max(dep[v]+1,dep[u]);
	}
//	cout<<u<<' '<<sub[u]<<endl;
	if(sub[u]==k){
		int ma1=0,ma2=0;
		for(auto v:g[u]){
			if(u==f)continue;
			if(dep[v]>ma1){
				ma2=ma1,ma1=dep[v];	
			} 
			else if(dep[v]>ma2)
			{
				ma2=dep[v];
			}
		}
		ans=min(ma1+ma2+1,ans);
	}
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		ans=INT_MAX;
		memset(g,0,sizeof g);
		memset(sub,1,sizeof sub);
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		if(k==2){
			cout<<1<<"\n";
			continue;
		} 
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;	
}

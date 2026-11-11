#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define dbg(x) cout<<#x<<" "<<x<<endl;
vector<int>edge[1000010];
int dep[1000010];
int mx,id;
void dfs(int x,int fa){
	for(auto i:edge[x])if(i!=fa){
		dep[i]=dep[x]+1;
		if(dep[i]>mx)mx=dep[i],id=i;
		dfs(i,x);
	}
	return;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			edge[u].push_back(v);
			edge[v].push_back(u);
		}
		memset(dep,0,sizeof(dep));
		dep[1]=1;
		dfs(1,0);
		//dbg(mx)
		mx=0;
		memset(dep,0,sizeof(dep));
		dep[id]=1;
		dfs(id,0);
		cout<<(mx-k+1)/2<<endl;
	}
	return 0;
}


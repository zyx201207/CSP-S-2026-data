#include<bits/stdc++.h>
using namespace std;
const int M=5e5+5,N=505;
int c,n,m,d,q,ans=0x3f3f3f;
int w[M];
struct edge{
	int y,z;
};
vector<edge>mp[M+N];
bool vis[M+N];
void dfs(int st,int ed,int cnt){
	if(st==ed){
		ans=min(ans,cnt);
		return;
	}
	for(int i=0;i<mp[st].size();i++){
		if(!vis[mp[st][i].y]){
			vis[mp[st][i].y]=true;
			dfs(mp[st][i].y,ed,cnt+mp[st][i].z);
			vis[mp[st][i].y]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=m+1;i<=n+m;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			edge x;
			cin>>x.y>>x.z;
			mp[i].push_back(x);
			edge a;
			a.y=i,a.z=x.z;
			mp[x.y].push_back(a);
		}
	}
	while(q--){
		int x,y;
		ans=0x3f3f3f;
		cin>>x>>y;
		dfs(x,y,w[x]);
		cout<<ans+w[y]<<endl;
	}
	return 0;
}

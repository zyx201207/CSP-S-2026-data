#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k;
int dis1[1005],a[505][1005],t[505][1005];
struct Seg{
	int id;
	int v;
};
vector<Seg> e[1005];
struct state{
	int id;
	int num;
};
struct node{
	vector<state> cnt;
	int sum;
}dis2[1005];
bool vis[1005];
int ans=INT_MAX;
void dfs(int u,int sum,int end){
	if(u==end){
		ans=min(ans,sum);
		return;		
	}		 
	for(int i=0;i<e[u].size();i++){
		int nv=e[u][i].v;
		if(vis[nv]==1)continue;
		vis[nv]=1;
		if(nv==end&&dis2[nv].cnt.size()!=1){
			int tt=e[u][i].id,dd;
			for(int j=0;j<dis2[nv].cnt.size();j++){
				if(dis2[nv].cnt[j].id==tt){
					dd=dis2[nv].cnt[j].num;	
				}
			}
//			if(end==2)cout<<"snb"<<dd<<endl; 
			dfs(nv,sum+dd,end);
		}	
		else dfs(nv,sum+dis2[nv].sum,end);
		vis[nv]=0;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	bool flag=1;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>dis1[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		if(k>2)flag=0;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
			if(j!=1){
				e[a[i][j-1]].push_back({i,a[i][j]});
				e[a[i][j]].push_back({i,a[i][j-1]});
			}
			dis2[a[i][j]].cnt.push_back({i,t[i][j]});
			dis2[a[i][j]].sum+=t[i][j];
		} 
	} 
//	for(int i=1;i<=m;i++){
//		cout<<i<<" ";
//		for(int j=0;j<e[i].size();j++){
//			cout<<e[i][j].v<<" ";
//		}
//		cout<<endl;
//		cout<<dis1[i]<<" ";
//		cout<<endl;
//		for(int j=0;j<dis2[i].cnt.size();j++){
//			cout<<dis2[i].cnt[j].id<<" "<<dis2[i].cnt[j].num<<endl;
//		}
//		cout<<dis2[i].sum;
//		cout<<endl<<endl;
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		ans=INT_MAX;
		dfs(x,0,y);
		ans+=dis1[x]+dis2[x].sum+dis1[y];
		cout<<ans<<endl;
	}
	return 0;
} 

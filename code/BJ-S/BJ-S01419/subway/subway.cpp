/*
subway

BFS



*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,l;
}p[505][50005];
struct bf{
	int now,how,xian,used;
};
int c,n,m,d,Q,x,y,ans,k[505],w[500005];
vector<int> t[500005];
queue<bf> q;
void bfs(int st,int en){
	for(auto it:t[st]){
		q.push({st,1,it,0});
	}
	while(!q.empty()){
		bf u=q.front();
		q.pop();
		if(u.now==en)
			ans=min(ans,u.used);
		else if(u.used<ans){
			if(u.how==1){//走
				for(int i=1;i<=k[u.now];i++){
					if(p[u.xian][i].a!=u.now)
						q.push({i,0,u.xian,u.used});
				}
			}else{//换站
				for(auto it:t[u.now]){
					q.push({u.now,1,it,u.used+w[it]+p[u.xian][u.now].l});
				}
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>p[i][j].a>>p[i][j].l;
			t[p[i][j].a].push_back(i);
		}
	}
	while(Q--){
		cin>>x>>y;
		ans=1e9;
		bfs(x,y);
		cout<<ans<<endl;
	}
	return 0;
}

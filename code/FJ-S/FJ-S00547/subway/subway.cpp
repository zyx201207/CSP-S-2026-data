#include<bits/stdc++.h>
using namespace std;
long long c,n,m,b,q,d[20],ans,r,t;
struct node{
	int x,step;
};
struct Node{
	int g,times;
};
vector<Node> v[510+500000];
long long times[510+500000];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>b>>q;
	for(int i=1;i<=m;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a;
			cin>>a>>t;
			v[i+500].push_back({a,t});
			v[a].push_back({i+500,t});
		}
	}
	for(int i=1;i<=q;i++){
		bool vis[510+500000]={0};
		int l,r;
		cin>>l>>r;
		queue<node> q;
		q.push({l,0});
		vis[l]=0;
		while(!q.empty()){
			node now=q.front();
			q.pop();
			if(now.x==r){
				ans=now.step;
			}
			for(int j=0;j<v[now.x].size();j++){
				int nom=v[now.x][j].g,times=v[now.x][j].times;
				if(!vis[nom]){
					vis[nom]=true;
					q.push({nom,now.step+times});
				}
			}
		}
		cout<<ans+d[l]+d[r]<<"\n";
	}
	return 0;
}

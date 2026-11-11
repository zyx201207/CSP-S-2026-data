#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=10000;
int c,n,m,d,q,w[MAXN],k[MAXN],p[MAXN],b,e,minn=INT_MAX;
struct node{
	int cost[MAXN];
}l[MAXN],po[MAXN];
struct nowcost{
	int sta;
	int ncost;
};
void bfs(){
	int vis[n];
	queue<nowcost>q;
	q.push({b,w[b]});
	while(!q.empty()){
		int nowsta=q.front().sta;
		int nowcost=q.front().ncost;
		q.pop();
		if(nowsta==e){
			minn=min(minn,nowcost+w[e]);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(po[nowsta].cost[i]&&!vis[i]){
				vis[i]=1;
				for(int j=1;j<=k[i];j++){
					if(po[i].cost[j])q.push({j,po[i].cost[j]+po[i].cost[nowsta]});
				}
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>p[i];
		for(int j=1;j<=p[i];j++){
			cin>>b>>e;
			l[i].cost[b]=e;
			po[b].cost[i]=e;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>b>>e;
		bfs();
		cout<<minn<<endl;
	}
	return 0; 
}


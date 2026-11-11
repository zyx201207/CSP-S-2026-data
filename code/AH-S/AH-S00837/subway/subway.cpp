#include<bits/stdc++.h>
using namespace std;
struct point{
	long long id,step;
}pt;
struct side{
	long long u,v;
}ed;
long long c,n,m,d,q,p,a,t,x,y,ans,w[500510];
long long vis[500510];
vector<side>edge[500510];
queue <point>qu;
void bfs(){
	long long pos,now;
	while(!qu.empty()){
		pos=qu.front().id;
		now=qu.front().step;
		qu.pop();
		if(pos==y){
			ans=min(ans,now+w[x]+w[y]);
		}
		vis[pos]=now;
		for(long long i=0;i<edge[pos].size();i++){
			if(vis[edge[pos][i].u]>now){
				pt.id=edge[pos][i].u;
				pt.step=now+edge[pos][i].v;
				qu.push(pt);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++){
		cin>>w[i];
	}
	for(long long i=1;i<=n;i++){
		cin>>p;
		for(long long j=1;j<=p;j++){
			cin>>a>>t;
			ed.u=a,ed.v=t;
			edge[i+m].push_back(ed);
			ed.u=i+m;
			edge[a].push_back(ed);
		}
	}
	for(long long i=1;i<=q;i++){
		cin>>x>>y;
		for(long long j=1;j<=n+m;j++){
			vis[j]=0x3f3f3f3f;
		}
		pt.id=x,pt.step=0;
		qu.push(pt);
		ans=0x3f3f3f3f;
		bfs();
		cout<<ans<<endl;
	}
	return 0;
}

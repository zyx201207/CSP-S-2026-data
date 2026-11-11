#include<bits/stdc++.h>
#define mp make_pair
using namespace std;
struct node{
	int to,nxt,w;
}e[4400005];
int head[4400005],cnt,vis[500005],dis[500005];
int cc,n,m,d,q,w[505],num,c[505],pa[505][25],p[505][25],l,r;
void add(int x,int y,int w){
	e[++cnt].to=y;
	e[cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].w=w;
}
void dij(int x){
	memset(dis,0x3f,sizeof dis);
	memset(vis,0,sizeof vis);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	dis[x]=0;
	q.push(mp(0,x));
	while(!q.empty()){
		int pos=q.top().second;
		q.pop();
		if(vis[pos]){
			continue;
		}
	//	cout<<pos<<" "<<q.top().first<<"\n";
		vis[pos]=1;
		for(register int i=head[pos];i;i=e[i].nxt){
			int v=e[i].to,w=e[i].w;
			if(dis[v]>dis[pos]+w){
				dis[v]=dis[pos]+w;
				q.push(mp(dis[v],v));
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>cc>>m>>n>>d>>q;
	for(register int i=1;i<=n;i++){
		cin>>w[i];
	}
	int v,ww;
	for(register int i=1;i<=m;i++){
		cin>>num;
		for(register int j=1;j<=num;j++){
			cin>>v>>ww;
			c[v]++;
			pa[v][c[v]]=ww;
			p[v][c[v]]=i;
		}
	}
	for(register int i=1;i<=n;i++){
		for(register int j=1;j<=c[i];j++){
			for(register int k=j+1;k<=c[i];k++){
				int x=p[i][j],y=p[i][k];
			//	cout<<i<<" "<<x<<" "<<y<<" "<<pa[i][j]+pa[i][k]<<'\n';
				add(x,y,pa[i][j]+pa[i][k]);
				add(y,x,pa[i][j]+pa[i][k]);
			}
		}
	}
	for(register int i=1;i<=q;i++){
		cin>>l>>r;
		int ans=1e9;
	//	cout<<l<<" "<<c[l]<<'\n';
		for(register int j=1;j<=c[l];j++){
			int x=p[l][j];
			dij(x);
		//	cout<<x<<'\n';
			for(register int k=1;k<=c[r];k++){
				ans=min(ans,dis[p[r][k]]+pa[l][j]+pa[r][k]);
			}
		}
		cout<<ans+w[l]+w[r]<<'\n';
	}
	return 0;
}


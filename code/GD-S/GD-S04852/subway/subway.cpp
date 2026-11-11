#include<bits/stdc++.h>
#define ll long long
#define PII pair<ll,int>
using namespace std;
const int ds=5e5;
int id,n,m,d,q,w[500005],k[505],cnt,tot,a[20000005][3],nxt[10000005],flags[2005];
ll dist[2005][2005];
vector<pair<int,int>>b[200005];
void add(int x,int y,int z){a[++tot][0]=y,a[tot][1]=nxt[x],nxt[x]=tot,a[tot][2]=z;}
priority_queue<PII,vector<PII>,greater<PII>>Q;
void dij(int s)
{
	for(int i=1;i<=cnt;i++) dist[s][i]=1e18,flags[i]=0;
	dist[s][s]=0,flags[s]=1;
	Q.push({0,s});
	while(!Q.empty())
	{
		int x=Q.top().second;Q.pop();
		for(int j=nxt[x];j;j=a[j][1]){
			int to=a[j][0],w=a[j][2];
			if(dist[s][x]+w<dist[s][to])
			{
				dist[s][to]=dist[s][x]+w;
				if(!flags[to]) flags[to]=1,Q.push({dist[s][to],to});
			}
		}
	}
}
int main()
{
//	system("fc subway.out subway3.ans");
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr); 
	cin>>id>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,x,y;j<=k[i];j++){
			cin>>x>>y;
			cnt++;
			if(j>1) add(cnt-1,cnt,0),add(cnt,cnt-1,0);
			b[x].emplace_back(cnt,y);
		}
	}
	int ji=cnt;
	for(int i=1;i<=m;i++){
		if(!b[i].size()) continue;
		cnt++;
		for(auto j:b[i]) add(cnt,j.first,j.second),add(j.first,cnt,j.second); 
	}
	if(id<=11)
	{
		for(int i=ji+1;i<=cnt;i++){
			dij(i);
		}
		while(q--)
		{
			int l,r;
			cin>>l>>r;
			ll val=(ll)w[l]+dist[ji+l][ji+r]+w[r];
			cout<<val<<endl;
		}
		return 0;
	}
	while(q--)
	{
		int l,r;
		cin>>l>>r;
		dij(ji+l);
		int val=(ll)w[l]+dist[ji+l][ji+r]+w[r];
		cout<<val<<endl;
	}
	return 0;
}

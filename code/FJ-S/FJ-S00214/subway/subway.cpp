#include<bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int N=5e3+10;
typedef pair<int,int> PII;
int c,n,m,d,q;
int w[N];
int dist[N];
bool dt[N];
vector<int> g[N],lu[N];

void dijskala(int st,int ed){
	priority_queue<PII,vector<PII>,greater<PII>> q;
	q.push({st,lu[st][st]});
	memset(dist,0,sizeof dist);
	dist[st]=lu[st][st];
	memset(dt,false,sizeof dt);
	
	while(q.size()){
		auto t=q.top();
		q.pop();
		
		if(dt[t.x]){
			continue;
		}
		dt[t.x]=true;
		
		for(int i=0;i<g[t.x].size();i++){
			int tx=g[t.x][i];
			if(!dt[tx]){
				continue;
			}
			if(tx==ed){
				dist[tx]=dist[t.x]+lu[t.x][tx];
				break;
			}else{
				dist[tx]=dist[t.x]+lu[t.x][tx]+lu[tx][tx];
			}
			
			q.push({tx,dist[tx]});
		}
	}
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			g[i].push_back(a);
			lu[i].push_back(t);
		}
	}
	
	while(q--){
		int a,b;
		cin>>a>>b;
		dijskala(a,b);
		cout<<w[a]+w[b]+dist[b]<<endl;
	}
	
	return 0;
}

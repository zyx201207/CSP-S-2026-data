#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define int128 __int128
#define gc getchar()
#define pii pair<long long,int>
#define inf 0x3f3f3f3f3f3f3f3f
using namespace std;
const int N=500+10;
const int M=5e5+10;
const int T=N*M;
int rd(){
	int x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
ll rdll(){
	ll x=0,f=1;char c=gc;
	for(;!isdigit(c);c=gc)if(c=='-')f=-1;
	for(;isdigit(c);x=x*10+c-'0',c=gc);
	return x*f;
}
int c,n,m,d,q;
ll w[M];int k[N];
vector<int>a[N];
vector<ll>t[N];
struct Edge{int v;ll val;};
vector<Edge>vt[N];
bool st[N];ll dist[N];
void Dijkstra(int s){
	priority_queue<pii,vector<pii>,greater<pii> >heap;
	for(int i=0;i<=n*m;i++)dist[i]=inf,st[i]=0;
	dist[s]=0;
	heap.push((pii){0,s});
	while(!heap.empty()){
		pii t=heap.top();heap.pop();
		int ver=t.second,d=t.first;
		if(d!=dist[ver])continue;
		if(st[ver])continue;
		st[ver]=true;
		for(int i=0;i<vt[ver].size();i++){
			int j=vt[ver][i].v;
			if(dist[j]>dist[ver]+vt[ver][i].val){
				dist[j]=dist[ver]+vt[ver][i].val;
				heap.push((pii){dist[j],j});
			}
		}
	}
}
int find1(vector<int>t,int tar){
	for(int i=0;i<t.size();i++)if(t[i]==tar)return i;
	return -1;
}
map<pair<int,int>,int>ti;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	c=rd(),n=rd(),m=rd(),d=rd(),q=rd();
	for(int i=1;i<=m;i++)w[i]=rdll();
	bool ch=1;
	for(int i=1;i<=n;i++){
		k[i]=rd();ll x,y;if(k[i]!=2)ch=0;
		for(int j=1;j<=k[i];j++){
			x=rd();a[i].push_back(x);
			y=rdll();t[i].push_back(y);
			ti[{i,x}]=y;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<a[i].size();j++){
			vt[i*a[i][j]].push_back((Edge){i*a[i][j-1],0});
			vt[i*a[i][j-1]].push_back((Edge){i*a[i][j],0});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			for(int l=0;l<a[i].size();l++){
				if(find1(a[j],a[i][l])!=-1){
					int pos=find1(a[j],a[i][l]);
					vt[i*m+a[i][l]].push_back((Edge){j*m+a[i][l],t[i][l]+t[j][pos]});
					vt[j*m+a[i][l]].push_back((Edge){i*m+a[i][l],t[i][l]+t[j][pos]});
				}
			}
		}
	}
	while(q--){
		int x=rd(),y=rd();ll ans=LLONG_MAX;
		for(int i=1;i<=n;i++){
			Dijkstra(i*m+x);
			for(int j=1;j<=n;j++){
				ans=min(ans,dist[j*m+y]+ti[{j,y}]+ti[{i,x}]);
			}
		}
		cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
}


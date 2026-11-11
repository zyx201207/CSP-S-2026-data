#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int M=5e5+7,N=507;
int c,n,m,d,q,w[M],k[N];
long long dist[N],line[N][N],floyed[N][N];
bool st[N];
vector<PII> son[N];
vector<PII> inLine[M];
unordered_map<int,int> inLineU[M];
unordered_map<int,pair<short,int> > u;
struct Subway{
	long long time;
	int line,beg;
	bool operator<(const Subway& p)const{
		return time>p.time;
	}
};
long long solve(int s,int t){//O(n+nlogn
	priority_queue<Subway> q;
	for(int i=1;i<=n;i++)	dist[i]=0x3f3f3f3f3f3f3f3fll,st[i]=0;
	for(auto i:inLine[s]){
		dist[i.first]=0;
		q.push({0,i.first,i.second});
	}
	long long res=0x3f3f3f3f3f3f3f3fll;
	while(!q.empty()){
		Subway p=q.top();q.pop();
		if(st[p.line])	continue;
		st[p.line]=1;
		int idx=0;
		for(int i=0;i<son[p.line].size();i++)	if(son[p.line][i].first==t)	idx=son[p.line][i].first;
		if(idx){
			if(!inLineU[t][p.line])	continue;
			res=min(res,p.time+inLineU[t][p.line]+p.beg);
			continue;
		}
		for(int i=1;i<=n;i++){
			if(i==p.line)	continue;
			if(dist[i]>dist[p.line]+line[p.line][i]){
				dist[i]=dist[p.line]+line[p.line][i];
				q.push({p.time+line[p.line][i],i,p.beg});
			}
		}
	}
	return res;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)	cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			int a,t;cin>>a>>t;
			son[i].push_back({a,t});
			inLine[a].push_back({i,t});
			inLineU[a][i]=t;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			floyed[i][j]=floyed[j][i]=0x3f3f3f3f3f3f3f3fll;
		}
	}
	for(int i=1;i<=n;i++){
		line[i][i]=0;
		for(int j=i+1;j<=n;j++){
			line[i][j]=0x3f3f3f3f3f3f3f3fll;
			floyed[i][j]=floyed[j][i]=0x3f3f3f3f3f3f3f3fll;
			for(auto k:son[i])	u[k.first].first+=1,u[k.first].second+=k.second;
			for(auto k:son[j])	u[k.first].first+=1,u[k.first].second+=k.second;
			for(auto k:u)	if(k.second.first==2)	line[i][j]=min(line[i][j],1ll*k.second.second);
			line[j][i]=line[i][j];
			u.clear();
		}
	}
//	for(int k=1;k<=n;k++){
//		for(int i=1;i<=n;i++){
//			for(int j=i+1;j<=n;j++){
//				floyed[i][j]=floyed[j][i]=min(floyed[i][j],floyed[i][k]+floyed[k][j]);
//			}
//		}
//	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)+w[x]+w[y]<<'\n';
	}
}
/*
0 2 5 20 2
4 1 9 2 5

3
1 5
2 7
4 6

3
2 3
3 4
5 7

1 3
1 2





0 3 7 20 2
8 3 6 1 7 2 9

3 
1 4 
2 5 
5 100

3
2 6
3 1
7 2

4 
3 2 
5 100 
4 6 
6 7

1 6
2 3

8 + 4 + 11 + 3 + 4 + 2 = 35.
3 + 6 + 1 + 6 = 16.

*/

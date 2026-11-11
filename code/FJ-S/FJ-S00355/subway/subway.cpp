#include<iostream> 
#include<vector> 
#include<stack> 
using namespace std;
typedef struct {
	int dest;
	long long k;
}edge;
typedef struct {
	int line;
	long long k;
}t_inter;
typedef vector<vector<edge>> graph;
vector<vector<long long>> cache;
void add(graph& g,int a,int b,long long k){
	g[a].push_back({b,k});
	g[b].push_back({a,k});
}
long long find(graph& g,int a,int b){
	if(cache[a].size()!=0)return cache[a][b];
	if(cache[b].size()!=0)return cache[b][a];
	cache[a]=vector<long long>(g.size(),0x7fffffffffffffff);
	cache[a][a]=0;
	stack<int> s;
	s.push(a);
	while(!s.empty()){
		int i=s.top();
		s.pop();
		for(const edge &e:g[i]){
			if(cache[a][e.dest]>cache[a][i]+e.k){
				cache[a][e.dest]=cache[a][i]+e.k;
				s.push(e.dest);
			}
		}
	}
	return cache[a][b];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,w[500000];
	vector<t_inter> inter[500000];
	cin>>c>>n>>m>>d>>q;
	graph g(n);
	for(int i=0;i<m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		while(k--){
			long long a,t;
			cin>>a>>t;
			inter[a-1].push_back({i,t});
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<inter[i].size();j++){
			for(int k=0;k<j;k++){
				add(g,inter[i][j].line,inter[i][k].line,inter[i][j].k+inter[i][k].k);
			}
		}
	}
	cache=vector<vector<long long>>(n);
	while(q--){
		long long x,y,mink=0x7fffffffffffffff;
		cin>>x>>y;
		x--;y--;
		for(const t_inter &i:inter[x]){
			for(const t_inter &j:inter[y]){
				long long tk=find(g,i.line,j.line)+i.k+j.k;
				if(mink>tk)mink=tk;
			}
		}
		cout<<mink+w[x]+w[y]<<endl;
	}
	return 0; 
}

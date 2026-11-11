#include<bits/stdc++.h>
using namespace std;
const int N=505,Q=1e5+5,M=5e5+10;
typedef pair<long long,long long> pi;
int c,n,m,d,q;
int w[M];
int k[N];


struct node{
	long long u,len;
};
vector<node> v[M];


long long dis[M];
bool f[M];
long long tp(long long x,long long y){
	
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pi,vector<pi>,greater<pi> > pq;
	pq.push({0,x});
	
	while(pq.empty()){
		
		pi o=pq.top();
		pq.pop();
		
		long long q=o.first;
		long long s=o.second;
		
		if(f[q]) continue; 
		for(auto e:v[s]){
			if(dis[e.u]>e.len+q){
				dis[e.u]=q+e.len;
				pq.push({dis[e.u],e.u});
				f[e.u]=true;
			}
		}
	}cout<<dis[y];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	cin>>c;
	
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	
	for(int i=1;i<=n;i++){
		cin>>k[i];
		
		if(k[i]==1){
			long long s,t;
			cin>>s>>t;
			v[s].push_back({0,t});
		}else{
			long long s1,t1,s2,t2;
			cin>>s1>>t1>>s2>>t2;
			v[s1].push_back({s2,t1+t2});
			v[s2].push_back({s1,t1+t2});
		}
	}
	
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		
		cout<<w[x]+w[y]+tp(x,y)<<endl;
	}
	return 0;
}


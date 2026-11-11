//GZ-S00006,裘滨溪,贵阳市第一中学 
#include<bits/stdc++.h>
using namespace std;
struct mystruct{
	int v;
	long long w;
};
long long w[500005];
vector<mystruct> G[505];
long long D[505][505];
bool b[505];
set<pair<long long,int> > s;
int c,n,m,d,q;
void Dijkstra(int idx){
	s.clear();
	for(int i=1;i<=m;i++){
		b[i]=false;
		D[idx][i]=1e18;
	}
	s.insert(make_pair(0,idx));
	D[idx][idx]=0;
	b[idx]=true;
	for(int t=1;t<=m;t++){
		long long val=(*s.begin()).first;
		int u=(*s.begin()).second;
		s.erase(s.begin());
		b[u]=true;
		for(int i=0;i<G[u].size();i++){
			int v=G[u][i].v;
			long long w=G[u][i].w;
			if(!b[v] && val+ww<D[idx][v]){
				D[idx][v]=val+ww;
				s.insert(make_pair(val+ww,v));
			}
		}
	}
}
int p[500005];
long long t[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	if(c>=1 && c<=6){
		for(int i=1;i<=n;i++){
			int len;
			cin>>len;
			for(int j=1;j<=len;j++){
				cin>>p[j]>>t[j];
			}
			for(int j=1;j<=len;j++){
				for(int k=j+1;k<=len;k++){
					G[p[j]].push_back(mystruct{p[k],t[j]+t[k]});
					G[p[k]].push_back(mystruct{p[j],t[j]+t[k]});
				}
			}
		}
		for(int i=1;i<=m;i++){
			Dijkstra(i);
		}
		for(;q--;){
			int u,v;
			cin>>u>>v;
			cout<<D[u][v]+w[u]+w[v]<<"\n";
		}
		return 0;
	}
	if(c>=7 && c<=11){
		for(int i=1;i<=n;i++){
			int k;
			cin>>k;
			int p1,p2;
			long long t1,t2;
			cin>>p1>>t1>>p2>>t2;
			G[p1].push_back(mystruct{p2,t1+t2});
			G[p2].push_back(mystruct{p1,t1+t2});
		}
		for(int i=1;i<=m;i++){
			Dijkstra(i);
		}
		for(;q--;){
			int u,v;
			cin>>u>>v;
			cout<<D[u][v]+w[u]+w[v]<<"\n";
		}
		return 0;
	}
	return 0;
}

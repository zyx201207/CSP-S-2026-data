#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+5;
long long c,n,m,d,q,x,y,aaa;
long long w[N],k[N];
struct jtm{
	int a,tt;
}name;
vector<jtm>v[N];
vector<int>way[N];
bool vis[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int t=0;t<m;t++){
		cin>>w[t];
	}
	for(int t=0;t<n;t++){
		cin>>k[t];
		for(int i=0;i<k[t];i++){
			cin>>name.a>>name.tt;
			v[t].push_back(name);
			way[name.a].push_back(t);
		}
	}
	for(int t=0;t<q;t++){
		memset(vis,0,sizeof(vis));
		cin>>x>>y;
		cout<<w[x]+v[way[x][0]][0].tt+w[y]<<endl;
	}
	return 0;
}

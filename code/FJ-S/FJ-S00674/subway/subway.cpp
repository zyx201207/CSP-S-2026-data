#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define INF 0x3f3f3f3f3f3f3f3f
int c,n,m,d,q;
vector<pair<int,int>> v[1000510];
int w[500010];
int di[1000510];
int st[1000510];
void f(int x){
	memset(di,INF,sizeof di);
	memset(st,0,sizeof st);
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,x});
	di[x]=0;
	while(!q.empty()){
		auto t=q.top();
		q.pop();
		if(st[t.second]==1) continue;
		st[t.second]=1;
		for(auto i:v[t.second]){
			if(di[i.first]>di[t.second]+i.second){
				di[i.first]=di[t.second]+i.second;
				q.push({di[i.first],i.first});
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		v[i].push_back({i+m,w[i]});
		v[i+m].push_back({i,w[i]});
	}
	for(int i=1;i<=n;i++){
		int l;
		int x[500010],t[500010];
		cin>>l;
		for(int j=1;j<=l;j++) cin>>x[j]>>t[j];
		for(int j=1;j<=l;j++){
			v[x[j]+m].push_back({2*m+i,t[j]});
			v[2*m+i].push_back({x[j]+m,t[j]});
		}
	}
//	for(int i=1;i<=2*m+n;i++){
//		cout<<i<<":";
//		for(auto j:v[i]){
//			cout<<j.first<<" "; 
//		}
//		cout<<endl;
//		if(i==m||i==2*m) cout<<endl;
//	}
	while(q--){
		int l,r;
		cin>>l>>r;
		f(l);
		cout<<di[r]<<endl;
	}
	return 0;
}

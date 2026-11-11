#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long w[500005];
struct road{
	long long num,be,en;
};
vector<road>roads;
bool cmp(road x,road y){return x.num<y.num;}
struct DSU{
	vector<int>fa,sz;
	DSU (int num){
		fa.resize(num+m+1);
		sz.assign(num+m+1,1);
		iota(fa.begin(),fa.end(),0);
	}
	int find(int x){
		return x==fa[x]?x:find(fa[x]); 
	} 
	bool unite(int a,int b){
		int a_fa = find(a),b_fa = find(b);
		if(a_fa==b_fa)return false;
		if(sz[a_fa]<sz[b_fa]){
			swap(a_fa,b_fa);
			swap(sz[a_fa],sz[b_fa]);
		}
		fa[b]=a_fa;
		sz[a_fa]+=sz[b_fa];
		return true;
	}
};
long long solve(int x,int y){
	long long ans=w[x]+w[y];
	queue<int>q;
	q.push(x);
	DSU dsu(n);
	for(int i=1;i<=(int)roads.size();i++){
		auto r = roads[i];
		if(dsu.unite(r.be,r.en))ans+=r.num;
	}
	return ans;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			road r ={t,a,i+m};
			roads.push_back(r);
		}
	}
	sort(roads.begin(),roads.end(),cmp);
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<solve(x,y)<<endl;
	}
	return 0;
}

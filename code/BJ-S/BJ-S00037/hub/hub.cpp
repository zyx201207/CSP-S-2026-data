#include<bits/stdc++.h>
using namespace std;
struct ed{
	int u,v;
}a[1000005];
struct DSU{
	vector<int> fa,sz;
	void init(int n){
		fa.resize(n+1);
		sz.assign(n+1,1);
		for(int i=0;i<n;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		return fa[x]=find(fa[x]);
	}
	bool unite(int x,int y){
		int rx=find(x);
		int ry=find(y);
		if(rx==ry) return false;
		if(sz[rx]<sz[ry]) swap(x,y);
		fa[ry]=rx;
		sz[rx]+=sz[ry];
		return true;
	}
};
int main(){
	ios::sync_with_stdio(0);cin.tie(nullptr);cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>a[i].u>>a[i].v;
		}
		int cnt=0;
		DSU dsu;
		dsu.init(n);
		for(int i=1;i<k;i++){
			if(dsu.unite(a[i].u,a[i].v)){
				cnt++;
			}
		}
		cout<<cnt<<'\n';
	}
	return 0;
}
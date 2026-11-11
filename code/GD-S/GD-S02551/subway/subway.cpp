#include<iostream>
#include<vector>
#define M 500005
#define N 505
using namespace std;
int c,n,m,d,q,w[M];
vector<int> a[N],t[N];
long long dfs(int u,int v,long long q){
	if(u==v) return q;
	long long minn=49350932783;
	for(int i=1;i<=n;i++){
		for(auto o:a[i]){
			if(u==o){
				for(auto o:a[i]){
			if(u!=o){
			minn=min(dfs(o,v,q+t[i][o]),minn);
			}
		}
			}
		}
	}
	return minn;
}
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			a[i].push_back(x);
			t[i].push_back(y);
		}
	}
	cin>>q;
	while(q--){
		int x,y;
		cin>>x>>y;
		if(x==y){
			cout<<0<<'\n';
			continue;
		}
		else cout<<dfs(x,y,w[x]+w[y])<<'\n';
	}
	return 0;
} 

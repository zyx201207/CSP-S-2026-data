#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,qq,w[500005],val[505][505];
struct node{
	int to;
	long long val;
}; 
vector<node> g[500005];
queue<int> q;
void check(int x,int y){
	int ans=1e18;
	for(auto i:g[x]){
		for(auto j:g[y]){
			ans=min(ans,i.val+j.val+val[i.to][j.to]+w[x]+w[y]);
		}
	}
	cout<<ans<<'\n';
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>qq;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		for(int j=1;j<=x;j++){
			int id;
			long long t;
			cin>>id>>t;
			g[id].push_back({i,t});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			val[i][j]=1e18;
		}
		val[i][i]=0;
	}
	for(int i=1;i<=m;i++){
		for(auto j:g[i]){
			for(auto k:g[i]){
				if(j.to==k.to){
					continue;
				}
				val[j.to][k.to]=min(val[j.to][k.to],j.val+k.val);
				val[k.to][j.to]=min(val[k.to][j.to],j.val+k.val);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				val[i][j]=min(val[i][j],val[i][k]+val[k][j]);
			}
		}
	}
	while(qq--){
		int x,y;
		cin>>x>>y;
		check(x,y);
	}
	return 0;
}
//rp++
//1.0s 1024kb
//0.6s 18kb
//100pts

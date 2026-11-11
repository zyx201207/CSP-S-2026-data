#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=510;
const int M=5e5+10;
int c,n,m,d,q,w[M],k[N];
map<int,int> a[N],t[N];
struct ff{
	int x,y;
}op[N];
int ans=1e18;
inline void dfs(int x,int y,int res){
	if(x==y){
		ans=min(ans,w[x]+w[y]+res);
		return;
	}
	if(res>ans){
		return;
	}
	for(int i=1;i<=n;i++){
		dfs(a[i][x],y,res+t[i][x]);
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1,aa,tt;j<=k[i];j++){
			cin>>aa>>tt;
			a[i][j]=aa;
			t[i][j]=tt;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>op[i].x>>op[i].y;
		dfs(op[i].x,op[i].y,0);
	}
	cout<<ans;
	return 0;
}

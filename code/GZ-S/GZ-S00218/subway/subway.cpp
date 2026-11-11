//GZ-S00218 ³ÂÍþºÀ 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
const ll inf=1e18+7;
ll c,n,m,d,q;
ll w[N],f[505][505];
struct node{
	ll idx;
	ll ti;
};
vector<node> g[N];
void solve(){
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int ki,ai,vi;
		cin>>ki;
		for(int j=1;j<=ki;j++){
			cin>>ai>>vi;
			g[ai].push_back({i,vi});
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		for(node u:g[i]){
			for(node v:g[i]){
				if(u.idx==v.idx) continue;
				f[u.idx][v.idx]=min(f[u.idx][v.idx],u.ti+v.ti);
				f[v.idx][u.idx]=min(f[v.idx][u.idx],u.ti+v.ti);
			}
		}
	}
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=n;j++){
//			cout<<f[i][j]<<' ';
//		}
//		cout<<'\n';
//	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(k==i || k==j) continue;
				if(f[i][j]>f[i][k]+f[k][j]){
					f[i][j]=f[i][k]+f[k][j];
					f[j][i]=f[i][j];
				}
			}
		}
	}
	int x,y;
	while(q--){
		cin>>x>>y;
		ll sum=inf;
		for(node u:g[x]){
			for(node v:g[y]){
				if(sum>w[x]+w[y]+u.ti+v.ti+f[u.idx][v.idx]){
					sum=w[x]+w[y]+u.ti+v.ti+f[u.idx][v.idx];
				//	cout<<sum<<" "<<u.idx<<" "<<v.idx<<" "<<u.ti<<' '<<v.ti<<' '<<f[u.idx][v.idx]<<endl;
				}
				if(u.idx==v.idx){
					sum=min(sum,w[x]+w[y]+u.ti+v.ti);
				//	cout<<sum<<"???\n";
				}
			}
		}
		cout<<sum<<endl;
	}
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	solve();
	return 0;
}

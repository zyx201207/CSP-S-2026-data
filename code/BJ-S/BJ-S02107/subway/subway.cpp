#include<bits/stdc++.h>
#define endl '\n'
#define ll long long
using namespace std;
const int maxn=5e5+10;
const int N=5e2+10;
const ll inf=1e18;
struct T{
	int x;
	ll t;
};
int c,n,m,q,D;
int w[maxn];
ll d[N][N];
vector<T> sub[maxn];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("subway.in","r",stdin);//
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int x,t;cin>>x>>t;
			sub[x].emplace_back(T{i,t});
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++) d[i][j]=(i!=j)*inf;
	for(int i=1;i<=m;i++){
		for(int j=0;j<sub[i].size();j++)
			for(int k=j+1;k<sub[i].size();k++){
				T x=sub[i][j],y=sub[i][k];
				d[x.x][y.x]=min(x.t+y.t,d[x.x][y.x]);
				d[y.x][x.x]=min(x.t+y.t,d[y.x][x.x]);
			}
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++) d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
	while(q--){
		int x,y;
		cin>>x>>y;
		ll ans=inf;
		for(T a:sub[x]) for(T b:sub[y])
			ans=min(ans,a.t+b.t+d[a.x][b.x]);
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,nN=505;
struct S{int t,id;};
int n,m,d,q,w[N],k,f[nN][nN],ans;
vector<S> e[N];
int min(int x,int y){if(x>y) x=y;return x;}
signed main(){
	cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) f[i][j]=1e18;
	for(int i=1;i<=n;++i) f[i][i]=0;
	for(int i=1;i<=m;++i) cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k;
		for(int j=1,a,t;j<=k;++j){
			cin>>a>>t;
			e[a].push_back({t,i});
			for(S v:e[a]) f[v.id][i]=f[i][v.id]=min(f[v.id][i],t+v.t);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=i;++j){
			for(int k=1;k<=i;++k){
				f[i][j]=f[j][i]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	for(int i=1,x,y;i<=q;++i){
		cin>>x>>y;ans=1e18;
		for(S v:e[x]) for(S u:e[y]){
			ans=min(ans,f[v.id][u.id]+v.t+u.t);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

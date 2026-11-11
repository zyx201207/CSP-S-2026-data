#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2+10;
struct awa{
	int u,v,w;
};
int w[maxn],a[maxn][maxn],t[maxn][maxn],k[maxn];
long long ans;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j];
			
		}
	}
	while(q--){
		int x,y,mx=1e9,my=1e9;
		cin>>x>>y;
		ans+=w[x]+w[y];
		cout<<ans;
	}
	return 0;
}


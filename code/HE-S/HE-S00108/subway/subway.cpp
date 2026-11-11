#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,n,m,d,q,a[N][N],w[N],k[N],t[N][N],vis[N][N],cnt[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
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
		int x,y,ans=0;
		cin>>x>>y;
		ans+=w[x]+w[y];
		cout<<w[x]<<" ";
		for(int i=x;i<y;i++){
			ans+=t[i][i]+t[i][i+1];
		}
		cout<<w[y]<<" ";
		cout<<ans<<"\n";
	}
	return 0;
}

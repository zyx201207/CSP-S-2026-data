#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=505;
const int M=500005;
int n,m,q,d[M],f[N][N],cnt[M],nxt[M][25],w[M][25],tmp;
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>n>>n>>m>>q>>q;
	for(int i=1;i<=m;i++) cin>>d[i];
	for(int i=1;i<=n;i++){
		cin>>tmp;
		while(tmp--){
			int x,a;cin>>x>>a;
			w[x][++cnt[x]]=a;
			nxt[x][cnt[x]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i==j) f[i][j]=0;
			else f[i][j]=1e18;
		}
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=cnt[k];i++){
			for(int j=1;j<=cnt[k];j++){
				f[nxt[k][i]][nxt[k][j]]=min(f[nxt[k][i]][nxt[k][j]],w[k][i]+w[k][j]);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[i][j]=min(f[i][k]+f[k][j],f[i][j]); 
			}
		}
	}
	while(q--){
		int x,y,mn=1e18;cin>>x>>y;
		if(x==y) mn=0;
		else{
			for(int i=1;i<=cnt[x];i++){
				for(int j=1;j<=cnt[y];j++){
					mn=min(mn,f[nxt[x][i]][nxt[y][j]]+w[x][i]+w[y][j]);
				}
			}
			mn+=d[x]+d[y];	
		}
		cout<<mn<<"\n";
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;

bool st; 
constexpr int N=505,M=5e5+5,D=25,inf=0x3f3f3f3f3f3f3f;
int c,n,m,d,q,k,x,y;
int w[M],cnt[M],a[M][D],t[M][D];
//input data

int f[N][N];
void floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k) continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
//floyd
bool ed;

signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
//	cerr<<(abs((&st-&ed)/1024/1024))<<"MB";
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x>>y;
			cnt[x]++;
			a[x][cnt[x]]=i,t[x][cnt[x]]=y;
		}	 
	}
	for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) if(i!=j) f[i][j]=inf;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=cnt[i];j++){
			for(int k=j+1;k<=cnt[i];k++) f[a[i][j]][a[i][k]]=f[a[i][k]][a[i][j]]=min(f[a[i][j]][a[i][k]],t[i][j]+t[i][k]);
		}
	}
	floyd();
	for(;q--;){
		cin>>x>>y;
		int ans=inf;
		for(int i=1;i<=cnt[x];i++){
			for(int j=1;j<=cnt[y];j++) ans=min(ans,f[a[x][i]][a[y][j]]+t[x][i]+t[y][j]);
		}
		cout<<ans+w[x]+w[y]<<'\n';
	}
}

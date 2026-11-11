#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int c,n,m,d,q,w[M],k,x,y,ans,p[N],cnt;
int a[N][M],t[N][N];
bool b[M][N],f;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
			b[a[i][j]][i]=true;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		for(int j=1;j<=n;j++)
			if(b[x][j]&&b[y][j])
				p[++cnt]=w[x]+w[y]+t[j][x]+t[j][y];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				for(int k=1;k<=n;k++){
					if((b[x][j]&&b[i][j])&&(b[y][k]&&b[i][k]))
						p[++cnt]=w[x]+w[y]+t[j][x]+t[k][y]+t[j][i]+t[k][i];
				}
			}
		}
		ans=p[1];
		for(int i=2;i<=cnt;i++)
			ans=min(ans,p[i]);
		cout<<ans<<endl;
	}
	return 0;
}

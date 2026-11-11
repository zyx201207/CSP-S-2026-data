//贵阳第一中学 GZ-S00116 胡祺然 
#include<iostream>
#include<cstring>
#define int long long
using namespace std;
const int N=510,M=5e5+10;
int f[N][N],c,n,m,d,q,w[M],e[M][22],tot[M],val[M][22],ans,ans1;
void Floyd(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(f[i][k]==-1||f[k][j]==-1)continue;
				if(f[i][j]==-1)f[i][j]=f[i][k]+f[k][j];
				else f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int x,y,l,a,t;
	cin.tie(0);
	ios::sync_with_stdio(0);
	memset(f,-1,sizeof(f)); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>a>>t;
			e[a][++tot[a]]=i;
			val[a][tot[a]]=t;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=tot[i];j++){
			for(int k=1;k<=tot[i];k++){
				f[e[i][j]][e[i][k]]=val[i][j]+val[i][k];
			}
		}
	}
	for(int i=1;i<=n;i++){
		f[i][i]=0;
	}
	Floyd();
	while(q--){
		cin>>x>>y;
		ans=1e15;
		for(int i=1;i<=tot[x];i++){
			for(int j=1;j<=tot[y];j++){
				if(f[e[x][i]][e[y][j]]==-1)continue;
				ans1=val[x][i]+val[y][j]+f[e[x][i]][e[y][j]];
				ans=min(ans,ans1);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}

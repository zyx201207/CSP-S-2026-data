#include<bits/stdc++.h>
using namespace std;
const int N=507,D=27,M=5e5+7;
struct Node{ int to,val; };
int csd,m,n,d,q;
int w[M],k[M];
int a[N][M],t[N][M];
long long ans,c[N][D];
signed main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csd>>m>>n>>d>>q;
	for(int i=1;i<=n;i++) cin>>w[i];
	for(int i=1;i<=m;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++)
			cin>>a[i][j]>>t[i][j],c[a[i][j]][i]=t[i][j];
	}
	for(int i=1;i<=q;i++){
		int u,v;ans=0;
		cin>>u>>v;
		if(m==1){
			for(int i=1;i<=k[1];i++) if(a[1][i]==u||a[1][i]==v) ans+=t[1][i];
			ans+=w[u]+w[v];
		}else if(m==2){
			for(int kkk=1;kkk<=n;kkk++)
				for(int i=1;i<=k[kkk];i++)
					if(a[kkk][i]==u||a[kkk][i]==v) ans+=t[kkk][i];
			long long minn=LONG_LONG_MAX;
			for(int i=1;i<=n;i++)
				if(c[i][1]!=0&&c[i][2]!=0) minn=min(minn,c[i][1]+c[i][2]);
			ans+=minn+w[u]+w[v];
		}
	} 
	return 0;
}



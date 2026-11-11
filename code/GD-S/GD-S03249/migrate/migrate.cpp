#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+10,M=5e3+10;
int c,t,n,ma,dis[M][M],m[M][M],cnt[M][M];
ll d,a[N],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--) {
		memset(dis,0x3f,sizeof dis);
		memset(m,0,sizeof m);
		ans=0;
		scanf("%d%lld",&n,&d);
		for(int i=1; i<=n; i++)
			scanf("%lld",a+i);
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(a[j]-a[i]>d) break;
				dis[i][j]=dis[j][i]=1;
			}
		}
		for(int k=1; k<=n; k++)
			for(int i=1; i<=n; i++)
				for(int j=1; j<=n; j++)
					if(dis[i][j]>dis[i][k]+dis[k][j])
						dis[i][j]=dis[i][k]+dis[k][j];
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++)
//				cout<<dis[i][j]<<' ';
//			cout<<endl;
//		}
		
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				for(int k=j+1; k<=n; k++)
					if(dis[i][k]<1e9&&dis[i][j]<1e9&&dis[j][k]<1e9&&dis[i][k]==dis[i][j]+dis[j][k])
						m[i][k]=++m[k][i];
		
//		for(int i=1; i<=n; i++) {
//			for(int j=1; j<=n; j++)
//				cout<<m[i][j]<<' ';
//			cout<<endl;
//		}
//		cout<<endl;
		
		for(int i=1; i<=n; i++)
			for(int j=i+1; j<=n; j++)
				if(m[i][j]==2) ans++;
		printf("%d\n",ans);
	}
	
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6


*/


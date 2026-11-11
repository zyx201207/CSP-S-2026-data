#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=305,NN=2e6+5,inf=0x3f3f3f3f;
int w[N][N],cnt[N][N];
ll a[NN];
int c,t,n;
ll d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		if(c<=6){
			scanf("%d%lld",&n,&d);
			memset(w,0x3f,sizeof w);
			memset(cnt,0,sizeof cnt);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				w[i][i]=0;
			}
			for(int i=1;i<=n;i++)
				for(int j=1;j<i;j++)
					if(a[i]-a[j]<=d){
						w[i][j]=w[j][i]=1;
						cnt[i][j]=cnt[j][i]=1;
					}
			for(int k=1;k<=n;k++)
				for(int i=1;i<=n;i++)
					for(int j=1;j<=n;j++){
						if(i==j||k==i||k==j) continue;
						if(w[i][j]>w[i][k]+w[k][j]){
							w[i][j]=w[i][k]+w[k][j];
							cnt[i][j]=cnt[i][k]*cnt[k][j];
						}else if(w[i][j]==w[i][k]+w[k][j]){
							cnt[i][j]+=cnt[i][k]*cnt[k][j];
						}
					}	
			int ans=0;
			for(int v=2;v<=n;v++)
				for(int u=1;u<v;u++)
					if(cnt[u][v]==2)
						ans++;
			printf("%d\n",ans);
		}else if(c>=11&&c<=12){
			ll ans=0;
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++){
				scanf("%lld",&a[i]);
			}
			d/=(a[2]-a[1]);
			if(d==0){
				printf("%lld\n",d);
				continue;
			}
			for(int i=2;i<=n;i++){
				int res=i-1;
				int x=(res+d-1)/d,y=res%d;
				if(x==1||y==0) continue;
				if(y==d-1&&x==2) ans+=n-i+1;
			} 
			printf("%lld\n",ans);
		}
	} 
	return 0;
}

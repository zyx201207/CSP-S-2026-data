#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=1e6+5,NN=1005;
const ll inf=0x3f3f3f3f3f3f3f3f;
int n;
ll d,a[N],dis[NN][NN],cnt[NN][NN];
void work(){
	memset(dis,0x3f,sizeof(dis));
	memset(cnt,0,sizeof(0));
	cin>>n>>d;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++)dis[i][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(abs(a[j]-a[i])<=d)dis[i][j]=dis[j][i]=1,cnt[i][j]=cnt[j][i]=1; 
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			if(i==k)continue;
			for(int j=1;j<=n;j++){
				if(i==j||j==k)continue;
				if(dis[i][k]+dis[k][j]<dis[i][j]){
					dis[i][j]=dis[i][k]+dis[k][j];
					cnt[i][j]=cnt[i][k]*cnt[k][j];
				}else if(dis[i][k]+dis[k][j]==dis[i][j])cnt[i][j]=cnt[i][j]+cnt[i][k]*cnt[k][j];
			}
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(cnt[i][j]==2&&dis[i][j]!=inf){
				ans++;
			}
		}
	}
	printf("%lld\n",ans);
}
int main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)work();
	return 0;
}

#include<cstdio>
#include<algorithm>
using namespace std;
int c,T,n,dis[2000005],cnt[2000005];
long long d,x[2000005],ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d %d",&c,&T);
	while(T--){
		ans=0;
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;i++)scanf("%lld",&x[i]);
		x[0]=-4e18,x[n+1]=4e18;
		if(n==1){
			printf("0\n");
			continue;
		}
		if(c==11 || c==12){
			if(d<2*x[2]-2*x[1])printf("0\n");
			else printf("%lld\n",max(0LL,n-2*(d/(x[2]-x[1]))+1));
			continue;
		}
		if(c==13 || c==14){
			if(d>=x[n]-x[1])printf("0\n");
			else{
				int tot=0;
				for(int i=1;i<=n;i++)if(x[i]-x[1]<=d && x[n]-x[i]<=d)tot++;
				printf("%d\n",tot);
			}
			continue;
		}
		for(int i=1;i<=n;i++){
			dis[i]=0;
			for(int j=1;j<=n;j++)cnt[j]=0;
			cnt[i]=1;
			for(int j=i+1,lst0=i,lst1=i;j<=n;j++){
				if(x[j]-x[j-1]>d)break;
				if(x[j]-x[lst0]<=d)dis[j]=dis[lst0]+1;
				else dis[j]=dis[lst0]+2,lst1=lst0,lst0=j-1;
				for(int k=lst1;k<=lst0;k++)if(x[j]-x[k]<=d && dis[k]==dis[j]-1)cnt[j]+=cnt[k];
				if(cnt[j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

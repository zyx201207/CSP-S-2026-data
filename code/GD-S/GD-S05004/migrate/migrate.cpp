#include<bits/stdc++.h>
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
#define FR(i,a,b) for(int i=(a);i>=(b);i--)
#define ll long long
using namespace std;
const int MAXN = 2e6 + 10;
const ll inf = 1e18;

int n;
ll D,ans;
ll a[MAXN];
ll dis[MAXN],cnt[MAXN];

void Solve(){
	scanf("%d%lld",&n,&D),ans=0;
	FL(i,1,n) scanf("%lld",&a[i]);
	FL(u,1,n){
		FL(i,u,n) dis[i]=inf,cnt[i]=0;
		dis[u]=0,cnt[u]=1;
		FL(i,u,n){
			if(dis[i]==inf) continue;
			if(dis[i]!=inf&&cnt[i]==2) /*printf("u=%d,i=%d\n",u,i),*/ans++;
			FL(j,i+1,n){
				if(a[j]-a[i]>D) break;
				if(dis[j]>dis[i]+1) dis[j]=dis[i]+1,cnt[j]=cnt[i];
				else if(dis[j]==dis[i]+1) cnt[j]=min(cnt[j]+cnt[i],3ll);
			}
		}
	}
	printf("%lld\n",ans);
	return ;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int ID,Num;
	scanf("%d%d",&ID,&Num);
	while(Num--) Solve();
	return 0;
}
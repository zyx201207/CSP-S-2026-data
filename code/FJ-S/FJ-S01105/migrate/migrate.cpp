#include<bits/stdc++.h>
#define LL long long
using namespace std;
int c,t,n;
LL d,x[2000005],a[200005],ans;
map<LL,LL>mp,dist;
void dfs(LL ii,LL p,LL cnt){
//	printf("x%d Ä¿±ê%d dist%d?\n",x,cnt,dist[p]);
	if(p>cnt)return;
	if(p==cnt){
		a[++ans]=dist[p];
		return;
	}
	for(int j=ii+1;j<=n;j++){
		if(x[j]-x[ii]>d)break;
		dist[x[j]]=dist[x[ii]]+1;
		dfs(j,x[j],cnt);
		dist[x[j]]=0;	
	}
//	for(int i=1;i<=d;i++){
//		if(x+i>cnt)break;
//		if(mp[p+i]){
//			
//		}
//	}
} 
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		mp.clear();
		LL cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			mp[x[i]]=1;
		}
		for(LL i=1;i<=n;i++){
			for(LL j=i+3;j<=n;j++){
				dist.clear();
				LL mi=1e18;
				ans=0;
				memset(a,0,sizeof(a));
				dfs(i,x[i],x[j]);
				for(LL k=1;k<=ans;k++){
//					printf("%lld ",a[i]);
					mi=min(mi,a[k]);
				}
//				printf("\n");
				LL sum=0;
				for(LL k=1;k<=ans;k++)if(a[k]==mi)sum++;
				if(sum==2)cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}

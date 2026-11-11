#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000005;
int c,T,n,d;
int x[N];
int las[N],nxt[N],sum[N];
int pre[N],suf[N];
int vis[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	for(int o=1;o<=T;o++){
		scanf("%lld%lld",&n,&d);
		for(int i=0;i<=n+3;i++)
			x[i]=las[i]=nxt[i]=sum[i]=pre[i]=suf[i]=vis[i]=0ll;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
//			if()
		}
		int l=0;
		nxt[0]=0;
		for(int i=1;i<=n;i++){
			while(l+1<=n&&x[l+1]+d>=x[i]&&x[l+1]+d<x[i+1]){
				l++;
				nxt[l]=i;
			}
		}
		for(int i=l+1;i<=n;i++)
			nxt[i]=n; 
		l=n+1;
		las[n+1]=n+1;
		for(int i=n;i>=1;i--){
			while(l-1>=1&&x[i]+d>=x[l-1]&&x[i-1]+d<x[l-1]){
				l--;
				las[l]=i;
			}
		}
		for(int i=l-1;i>=1;i--)
			las[i]=1;
		for(int i=1;i<=n;i++){
			int x=las[i+1];
			if(nxt[i]-1>=i+1&&las[nxt[i]-1]!=i)x=min(x,las[las[nxt[i]-1]]);
//			printf("%lld ",x);
			if(las[i]==i||x<=las[i])pre[i]=1;
			else{
				if(x>i)
					pre[i]=i-las[i]-1+pre[las[i]]+1;
				else pre[i]=x-las[i]-1+pre[las[i]]+1;
			}
		}
//		printf("\n");
		for(int i=n;i>=1;i--){
			int x=nxt[i-1];
			if(las[i]+1<=i-1&&nxt[las[i]+1]!=i)x=max(x,nxt[nxt[las[i]+1]]);
//			printf("%lld ",x);
			if(nxt[i]==i||x>=nxt[i])suf[i]=1;
			else{
				if(x<i)
					suf[i]=nxt[i]-i-1+suf[nxt[i]]+1;
				else suf[i]=nxt[i]-x-1+suf[nxt[i]]+1;
//				printf("%lld\n",suf[i]);
			}
		}
//		printf("\n");
		int ans=0ll;
		for(int i=1;i<=n;i++){
			if(nxt[i]-2>=i&&nxt[nxt[i]-1]>nxt[i]&&nxt[nxt[i]-1]>nxt[nxt[i]-2]){
				sum[i]=nxt[nxt[i]-1]-nxt[nxt[i]-2];
//				if(!vis[nxt[nxt[i]-1]]){
					ans+=pre[i]*(suf[nxt[nxt[i]-1]]+(sum[i]-1ll));
//					ans+=(sum[i]-1ll)*pre[i];
//					vis[nxt[nxt[i]-1]]=1;
//				}
//				else ans+=suf[nxt[nxt[i]-1]]+sum[i]-1ll;
			}
		}
//		printf("id=%lld\n",o);
//		for(int i=1;i<=n;i++)
//			printf("%lld %lld %lld %lld %lld\n",las[i],nxt[i],pre[i],suf[i],sum[i]);
		printf("%lld",ans);
		printf("\n");
	}
	return 0;
} 

#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e6+5;
int cid,T,n,lst[N],nxt[N];
ll d,a[N],ans;
int lt[N],nt[N];
int pre[N],suf[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&cid,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		ans=0;
		for(int i=1;i<=n;++i) lt[i]=nt[i]=0;
		for(int i=1;i<=n;++i) scanf("%lld",&a[i]);
		for(int i=1,j=1;i<=n;++i){
			while(a[i]-a[j]>d) j++;
			lst[i]=j;
			if(j!=i) lt[j]++;
		}
		for(int i=n,j=n;i;i--){
			while(a[j]-a[i]>d) j--;
			nxt[i]=j;
			if(j!=i) nt[j]++;
		}
		for(int i=1;i<=n;++i){
			pre[i]=nt[i]+1;
			if(nxt[lst[i]]==i) pre[i]+=pre[lst[i]]-1;
		}
		for(int i=n;i>=1;i--){
			suf[i]=lt[i]+1;
			if(lst[nxt[i]]==i) suf[i]+=suf[nxt[i]]-1;
		}
		for(int i=1;i<=n;++i){
			int j=nxt[i],k=nxt[j];
			if(j<=i+1) continue;
			if(lst[k]==j-1&&lst[j-1]==i) ans+=1ll*pre[i]*suf[k]-1;
		}//ABA
		for(int i=1;i<=n;++i) ans+=1ll*(nt[i]-(nxt[i-1]==i))*(lt[i-1]-(lst[i]==i-1));//B
		for(int i=1;i<=n;++i){
			int j=nxt[i],k=nxt[j];
			if(j<=i+1) continue;
			if(lst[k]==j-1&&lst[j-1]!=i) ans+=suf[k]-1;
		}//BA
		for(int i=n;i;--i){
			int j=lst[i],k=lst[j];
			if(j>=i-1) continue;
			if(nxt[k]==j+1&&nxt[j+1]!=i) ans+=pre[k]-1;
		}//AB
		// for(int i=1;i<=n;++i) printf("%d ",lst[i]);printf("\n");
		// for(int i=1;i<=n;++i) printf("%d ",nxt[i]);printf("\n");
		printf("%lld\n",ans);
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000005
int C,T,n,d,x[N],lt[N],nt[N],pr[N],af[N],pre[N],aft[N],ans;
signed main(){
//	freopen("migrate4.in","r",stdin);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		scanf("%lld%lld",&n,&d),ans=0;
		for(int i=1;i<=n;i++) scanf("%lld",&x[i]),pr[i]=af[i]=pre[i]=aft[i]=lt[i]=nt[i]=0;
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&x[j+1]-x[i]<=d) j++;
			nt[i]=j;if(i!=j) pr[j]++;
		}
		for(int i=n,j=n;i;i--){
			while(j>1&&x[i]-x[j-1]<=d) j--;
			lt[i]=j;if(i!=j)af[j]++;
		}
		for(int i=1;i<=n;i++){
			if(lt[i]!=i&&nt[lt[i]]==i) pre[i]+=pre[lt[i]];
			if(nt[i]!=i&&lt[nt[i]]<=i) pre[nt[i]]++;
		}
		for(int i=n;i;i--){
			if(nt[i]!=i&&lt[nt[i]]==i) aft[i]+=aft[nt[i]];
			if(lt[i]!=i&&nt[lt[i]]>=i) aft[lt[i]]++;
		}
		for(int i=1;i<n;i++){
			int pree=pr[i+1]-(nt[i]==(i+1)),aftt=(af[i]-(lt[i+1]==i));
			if(lt[i]!=i&&nt[lt[i]]==i+1) pree+=pre[lt[i]];
			if(nt[i+1]!=i+1&&lt[nt[i+1]]==i) aftt+=aft[nt[i+1]];
			ans+=pree*aftt;
		}
		printf("%lld\n",ans);
	}
	return 0;
}

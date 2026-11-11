#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=2e6+7;
int subid,t,n;
ll d;
ll a[maxn];
int to[maxn],f[maxn][3];

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&subid,&t);
	while(t--){
		scanf("%d%lld",&n,&d);
		for(int i=0;i<=n+1;i++) to[i]=f[i][0]=f[i][1]=f[i][2]=0;
		for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
		for(int i=1,j=1;i<=n;i++){
			while(j<n&&a[j+1]<=a[i]+d) j++;
			to[i]=j;
		}
		for(int i=n;i;i--){
			if(to[i]==i) continue;
			int nxt=to[to[i]];
			if(nxt==to[i]) continue;
			if(to[i]-i==1){
				f[i][0]=f[to[i]][0]+nxt-to[i];
				f[i][1]=f[to[i]][1]+f[to[i]][2];
			}else if(to[i]-i==2){
				if(to[to[i]-1]==nxt){
					f[i][2]=f[to[i]][0]+nxt-to[i];
				}else if(to[to[i]-1]==nxt-1){
					f[i][0]=f[to[i]][0]+1;
					f[i][1]=f[to[i]][1];
					f[i][2]=nxt-1-to[i];
				}else{
					f[i][0]=f[to[i]][0]+nxt-to[to[i]-1];
					f[i][1]=f[to[i]][1]+f[to[i]][2];
					f[i][2]=to[to[i]-1]-to[i];
				}
			}else{
				if(to[to[i]-1]==nxt){
					if(to[to[i]-2]!=nxt) f[i][2]=f[to[i]][0]+nxt-to[to[i]-2];
				}else if(to[to[i]-1]==nxt-1){
					f[i][0]=f[to[i]][0]+1;
					f[i][1]=f[to[i]][1];
					f[i][2]=nxt-1-to[to[i]-2];
				}else{
					f[i][0]=f[to[i]][0]+nxt-to[to[i]-1];
					f[i][1]=f[to[i]][1]+f[to[i]][2];
					f[i][2]=to[to[i]-1]-to[to[i]-2];
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++) ans+=(ll)f[i][1]+f[i][2];
		printf("%lld\n",ans);
	}
	return 0;
} 

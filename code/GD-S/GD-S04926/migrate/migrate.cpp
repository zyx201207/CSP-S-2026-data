#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
int cid,T,n,d,a[N],res,f[N],f2[N];
void solve(){
	scanf("%lld%lld",&n,&d); res=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			int ans=1,cnt=0,now=i;
			for(int k=i;k<j;k++){
				if(a[k+1]-a[k]>d) ans=0;
				if(a[k]-a[now]<=d&&a[k+1]-a[now]>d) f[k]=1,now=k;
			}
			now=j;
			for(int k=j;k>i;k--){
				if(a[now]-a[k]<=d&&a[now]-a[k-1]>d) f2[k]=1,now=k;
//				{
//					now=k;
//					if(!f[k]){
//						if(f[k+1]) cnt++;
//						else ans=0;
//					}
//				}
			//	else if(f[k]) ans=0;
			}
			for(int k=i;k<=j;k++)
				if(f[k]!=f2[k]){
					if(!f[k]&&f[k+1]&&!f2[k+1]||f[k]&&!f[k-1]&&f2[k-1]) cnt++;
					else ans=0;
				}
		//	printf("[%d %d]:cnt=%d,ans=%d\n",i,j,cnt,ans);
		//	for(int k=i;k<=j;k++) printf("%d ",f[k]);printf("\n");
		//	for(int k=i;k<=j;k++) printf("%d ",f2[k]);
			if(cnt==2) res+=ans;
			for(int k=i;k<=j;k++) f[k]=f2[k]=0;
		}
	}
	printf("%lld\n",res);
}
void solve2(){
	scanf("%lld%lld",&n,&d); res=0;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	int s=d/(a[2]-a[1]);
	printf("%lld\n",(s>1)?max(0ll,n+1-2*s):0);
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&cid,&T);
	while(T--){
		if(cid<=6) solve();
		else if(cid==11||cid==12) solve2();
	}
	return 0;
}


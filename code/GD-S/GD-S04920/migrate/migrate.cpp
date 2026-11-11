#include <bits/stdc++.h>
using namespace std;
int c,T,n,ne[2000001],f[2000001],f1[2000001];
long long x[2000001],d,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		ans=0;
		for(int i=1;i<=n;i++){
			ne[i]=0;
			f[i]=0;
			f1[i]=0;
		}
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=n,cnt=n;i>0;i--){
			while(x[i]-x[cnt]<=d) cnt--;
			ne[i]=cnt+1;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(ne[j]<=i){
					f[j]=1;
					f1[j]=1;
					continue;
				}
				f[j]=f[ne[j]]+1;
				f1[j]=f1[ne[j]];
				if(ne[j]+1<j&&f[j]==f[ne[j]+1]+1) f1[j]+=f1[ne[j]+1];
				if(ne[j]+2<j&&f[j]==f[ne[j]+2]+1) f1[j]=3;
				if(f1[j]==2) ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

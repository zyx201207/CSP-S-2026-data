#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,t,n,d,x[2000005],f[2000005],g[2000005];
#undef int
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	#define int long long
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&d);
		int ans=0;
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				f[j]=1e18;
				g[j]=0;
			}
			f[i]=0;
			g[i]=1;
			int l=i,r=i,sum=0;
			for(int j=i+1;j<=n;j++){
				while(l<j&&x[j]-x[l]>d)l++;
				if(l==j)break;
				r=l;
				sum=g[r];
				while(r<j&&f[r]==f[l]){
					r++;
					sum+=g[r];
				}
				sum-=g[r];
				r--;
				f[j]=f[l]+1;
				g[j]=sum;
				if(g[j]==2)ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

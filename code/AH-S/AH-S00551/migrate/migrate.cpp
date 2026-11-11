#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=2e6+5;
LL c,T,n,d,ans;
LL a[N],al[N],ar[N],f[N],g[N],lst[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&T);
	while(T--){
		ans=0;
		scanf("%lld%lld",&n,&d);
		for(LL i=1;i<=n;i++){
			scanf("%lld",a+i);
		}
		sort(a+1,a+n+1);
		for(LL i=1;i<=n;i++){
			LL l=1,r=i;
			while(l<r){
				LL mid=(l+r)>>1ll;
				if(a[mid]+d<a[i]){
					l=mid+1;
				}else{
					r=mid;
				}
			}
			if(a[l]+d>=a[i]){
				al[i]=l;
			}
			l=i,r=n;
			while(l<r){
				LL mid=(l+r+1)>>1ll;
				if(a[mid]-d>a[i]){
					r=mid-1;
				}else{
					l=mid;
				}
			}
			if(a[r]-d<=a[i]){
				ar[i]=r;
			}
			//printf("%lld %lld\n",al[i],ar[i]);
		}
		for(LL i=1;i<=n;i++){
			fill(f,f+n+1,0);
			fill(g,g+n+1,0);
			fill(lst,lst+n,0);
			f[i]=0;g[i]=1;lst[0]=i;
			//printf("%lld\n",i);
			for(LL j=i+1;j<=n;j++){
				LL jl=max(al[j],i);
				if(jl==j){
					break;
				}
				f[j]=f[jl]+1;
				lst[f[j]]=j;
				LL cur=g[lst[f[jl]]]-g[jl-1];
				//printf("%lld ",lst[f[jl]]);
				if(cur==2){
					ans++;
				}
				g[j]=g[j-1]+cur;
			}
			//printf("\n");
		}
		printf("%lld\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

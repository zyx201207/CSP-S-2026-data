#include<bits/stdc++.h>
using namespace std;
long long t,n,d,a[2000005],ans,i,j,k,l,b[2000005],c[2000005],cnt,e[2000005],f[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&t,&t);
	while(t--){
		scanf("%lld%lld",&n,&d),ans=j=k=l=cnt=0;
		for(i=1;i<=n;i++)
			scanf("%lld",&a[i]),b[i]=0;
		for(i=1;i<=n;i++){
			while(a[j+1]<=a[i]+d&&j<n){
				j++;
			}
			if(j>=i+2){
				while(a[l+1]<=a[j-2]+d&&l<n)l++;
				while(a[k+1]<=a[j-1]+d&&k<n)k++;
				if(k!=l){
					if(c[cnt]==l+1)b[cnt]=i;
					else b[++cnt]=i,c[cnt]=l+1;
				}
			}
		}
		e[1]=1;
		for(i=2;i<=n;i++)
			if(a[i]-a[i-1]<=d)
				e[i]=e[i-1];
			else e[i]=i;
		f[n]=n;
		for(i=n-1;i>=1;i--)
			if(a[i+1]-a[i]<=d)
				f[i]=f[i+1];
			else f[i]=i;
		c[cnt+1]=n+1;
		for(i=1;i<=cnt;i++){
			j=max(b[i-1],e[b[i]]-1);
			k=min(c[i+1],f[c[i]]+1);
			ans+=(b[i]-j)*(k-c[i]);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

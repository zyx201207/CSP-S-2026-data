#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,x,ans,a[N],s[N],c[N],p[N];
bool ok=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	} 
	sort(a+1,a+n+1);
	for(int i=2;i<=n-1;i++){
		if(a[i]-a[i-1]!=a[i+1]-a[i]) ok=0;
	}
	if(ok){
		for(int i=1;i<=n;i++){
			c[i]=c[i-1]+((a[i]-a[i-1])*(long long)(i-1));
		}
		if(lower_bound(c+1,c+n+1,m)-c){
			int t=lower_bound(c+1,c+n+1,m)-c;
			if(c[t]==m) printf("%d",t);
			else if(c[t]>m) printf("%d",t-1);
		}else printf("%d",n);
	}else{
		for(int i=1;i<=n;i++){
			p[i]=p[i-1]+((a[i]-a[i-1])*(long long)(i-1));
		}
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				long long x=p[j]-p[i]-(long long)i*(a[j]-a[i]);
				if(m>=x) ans=max(ans,(long long)(j-i+1));
			}
		}
		printf("%lld",ans);
	}
	return 0;
}

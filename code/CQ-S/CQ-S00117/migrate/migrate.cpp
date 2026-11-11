#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
typedef long long ll;
ll c,t;
ll n,m,a[MAX];
ll ans=0;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--){
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++){scanf("%lld",a+i);}
		for(int i=1;i<=n;i++){
			for(int j=i+3;j<=n;j++){
				int r=upper_bound(a+1,a+1+n,a[i]+m)-a-1;
				int l=lower_bound(a+1,a+1+n,a[j]-m)-a;
//				l=max(i,l),r=min(r,j);
				int len=(l<=r?r-l+1:0);
				ans+=(len==2);
//				printf("%d %d:%d %d\n",i,j,l,r);
			}
		}printf("%lld\n",ans);
		ans=0;
	}
	return 0;
}

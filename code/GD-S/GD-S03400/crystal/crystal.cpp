#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+15;
ll n,m,a[N],ans=0,sum,s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	int l=1;
	a[0]=a[1];
	for(ll i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
		sum+=(a[i]-a[i-1])*(i-l);
		while(sum>m){
			sum-=(a[i]-a[l]);
			l++;
		}
		ans=max(ans,(i-l+1));
	}
	printf("%lld",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

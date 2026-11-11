#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N=5*1e5+5;
LL n,m,ans=0;
LL a[N],s[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	LL h=1;
	for(LL i=1;i<=n;i++){
		s[i]=a[i]+s[i-1];
		while((i-h+1)*a[i]-(s[i]-s[h-1])>m){
			h++;
		}
		ans=max(ans,i-h+1);
	}
	cout << ans;
	return 0;
}

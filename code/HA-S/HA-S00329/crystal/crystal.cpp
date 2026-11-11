#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500005],lt;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		ll t=m,cnt=1;
		int j=i-1;
		for(;j>=1;j--){
			if(t-a[i]+a[j]>=0){
				t=t-a[i]+a[j];
				cnt++;
			}
			else{
				break;
			}
		}
		lt=max(lt,cnt);
	}
	printf("%lld",lt);
	return 0;
}

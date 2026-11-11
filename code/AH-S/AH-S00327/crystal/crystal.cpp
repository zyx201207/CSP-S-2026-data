#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
ll n,m;
ll a[500005],gans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		int tmp=m;ll ans=1;
		for(int j=i-1;j>=1;j--){
			if(tmp<=0)break;
			tmp-=a[i]-a[j];
			ans++;
		}
		gans=max(gans,ans);
	}
	cout<<gans;
	return 0;
}

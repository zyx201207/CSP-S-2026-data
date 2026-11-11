#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n,ans;
ll m,a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	ll s=0;
	for(int i=1,j=0;i<=n;i++){
		while(j<n&&1ll*(j-i+1)*a[j+1]-s<=m){
			j++;
			s+=a[j];
		}
		ans=max(ans,j-i+1);
		s-=a[i];
	}
	printf("%d\n",ans);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long N=1e18;
long long n,m,a[N];

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int ans=0;
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(a[i]==a[j])ans++;
		}
	}
	printf("%lld",ans);
	return 0;
 } 

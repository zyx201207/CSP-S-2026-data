#include<bits/stdc++.h>
using namespace std;
int n;
long long ans=0;
long long m;
long long a[500010];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		long long z=m;
		long long maxx=0;
		for(int j=i;j>=1 and a[i]-a[j]<=z;j--){
			maxx++;
			z=z-a[i]+a[j];
		}
		ans=max(ans,maxx);
	}
	printf("%lld",ans);
}

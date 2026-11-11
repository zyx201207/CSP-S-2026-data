#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 1;
int n;
ll m,a[N],w[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		w[i]=w[i-1]+(i-1)*(a[i]-a[i-1]);
	int i=1,j=1,ans=1;
	while(i<=j&&j<=n)
	{
		j++;
		if(j>n)
			break;
		while(w[j]-w[i]-(i-1)*(a[j]-a[i])>m)
			i++;
		ans=max(ans,j-i+1);
	}
	printf("%d",ans);
	return 0;
}

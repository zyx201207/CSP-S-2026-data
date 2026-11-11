#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int ans;
int n;
int a[N];
char c[N];


signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i = 1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		scanf(" %c",&c[i]);
	}
	int l = 1,r = n;
	while(r>l)
	{
		if(c[l]==c[r])
		{
			if(a[l]>a[r]) a[l]-=a[r--];
			else if(a[l]==a[r]) a[l++]-=a[r--];
			else a[r]-=a[l++];
		}
		else
		{
			if(a[l]>a[r]) ans+=a[r],a[l]-=a[r],r--;
			else if(a[l]==a[r]) ans+=a[l],a[l]-=a[r],l++,r--;
			else ans+=a[l],a[r]-=a[l],l++;
		}
	}
	printf("%lld",ans);
	return 0;
}

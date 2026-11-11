#include<bits/stdc++.h>
#define int long long 
using namespace std;
constexpr int N=2e5+5;
int n,len,ans;
int cnt[N];
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&cnt[i]);
		cin>>c[i];
		len+=cnt[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		if(c[l]!=c[r])
		{
			if(cnt[l]<cnt[r])
			{
				ans+=cnt[l];
				cnt[r]-=cnt[l++];
			}
			else if(cnt[l]>cnt[r])
			{
				ans+=cnt[r];
				cnt[l]-=cnt[r--];
			}
			else 
			{
				ans+=cnt[l];
				++l;--r;
			}
		}
		else
		{
			if(cnt[l]<cnt[r]) cnt[r]-=cnt[l++];
			else if(cnt[l]>cnt[r]) cnt[l]-=cnt[r--];
			else ++l,--r;
		}
	}
	printf("%lld",ans);
	return 0;
}

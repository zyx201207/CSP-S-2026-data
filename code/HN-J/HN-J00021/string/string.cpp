#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
#define int long long
int n,li,ri;
long long a[N],s[N],mid,l,r,ans;
char b[N];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i]>>b[i];
		if(b[i]==b[i-1])
		{
			a[i-1]+=a[i];
			n--;
			i--;
		}
	}
	for(int i=1;i<=n;++i)
	{
		s[i]=s[i-1]+a[i];
	}
	mid=(s[n]+1)>>1;
	if(s[n]&1)
	{
		l=mid-1,r=mid+1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]>=l)
			{
				li=i;
				break;			
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(s[i]>=r)
			{
				ri=i;
				break;			
			}
		}
		int len;
		while(l)
		{
			len=min(l-s[li-1],s[ri]-r+1);
			l-=len,r+=len;
			if(b[li]!=b[ri])ans+=len;
			if(l-s[li-1]==0)li--;
			if(s[ri]-r+1==0)ri++;
			
		}
	}
	else
	{
		l=mid,r=mid+1;
		for(int i=1;i<=n;++i)
		{
			if(s[i]>l)
			{
				li=i;
				break;			
			}
		}
		for(int i=1;i<=n;++i)
		{
			if(s[i]>r)
			{
				ri=i;
				break;			
			}
		}
		int len;
		while(l)
		{
			len=min(l-s[li-1],s[ri]-r+1);
			l-=len,r+=len;
			if(b[li]!=b[ri])ans+=len;
			if(l-s[li-1]==0)li--;
			if(s[ri]-r+1==0)ri++;
		}
	}
	cout<<ans;
	return 0;
}

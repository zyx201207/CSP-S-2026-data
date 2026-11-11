//string
#include<bits/stdc++.h>
using namespace std;
long long s[200005],tota,totb;
char sc[200005];
long long a[200005];
char ac[200005];
long long b[200005];
char bc[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,len=0;
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>s[i]>>sc[i],len+=s[i];
	long long cnt=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt+s[i]>=len/2+1)
			{
				if(len/2-cnt!=0)
				{
					a[++tota]=len/2-cnt;
					ac[i]=sc[i];
				}
				break;
			}
			else
			a[++tota]=s[i],ac[tota]=sc[i],cnt+=s[i];
		}
		cnt=0;
		for(int i=n;i>=1;i--)
		{
			if(cnt+s[i]>=len/2+1)
			{
				if(len/2-cnt!=0)
				{
					b[++totb]=len/2-cnt;
					bc[totb]=sc[i];
				}
				break;
			}
			else
			b[++totb]=s[i],bc[totb]=sc[i],cnt+=s[i];
		}
	long long i=1,j=1,ans=0;
	while(i<=tota && j<=totb)
	{
		if(a[i]<=b[j])
		{
			if(a[i]==b[j])
			{
				if(ac[i]!=bc[j])
				ans+=a[i];
				i++,j++;
			}
			else
			{
				if(ac[i]!=bc[j])
				ans+=a[i];
				b[j]-=a[i];
				i++;
			}
		}
		else
		if(a[i]>b[j])
		{
			if(ac[i]!=bc[j])
			ans+=b[j];
			a[i]-=b[j];
			j++;
		}
	}
	cout<<ans;
	return 0;
}

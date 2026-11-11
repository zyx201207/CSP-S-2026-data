#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
const int INF=0x3f3f3f3f;
long long n,a[N],ans,last;
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	last=n;
	for(int i=1;i<=n;i++)
	{
		while(a[i])
		{
			if(c[i]!=c[last])
			{
				if(a[i]>=a[last])
				{
					ans+=a[last];
					a[i]-=a[last];
					a[last]=0;
					last--;
				}
				else
				{
					ans+=a[i];
					a[last]-=a[i];
					a[i]=0;
				}
			}
			else
			{
				if(a[i]>=a[last])
				{
					a[i]-=a[last];
					a[last]=0;
					last--;
				}
				else
				{
					a[last]-=a[i];
					a[i]=0;
				}
			}
		}
	}
	cout<<ans;
	return 0;
}


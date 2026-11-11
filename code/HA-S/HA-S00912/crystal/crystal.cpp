#include <bits/stdc++.h>
using namespace std;
const long long N=500000+10;
long long n,m;
long long a[N];long long b[N];

void teAB(int c)
{
	long long ans=0,cnt=0;
    for(int i=1;i<=n;i++)
    {
    	ans+=(i-1)*c;
    	if(ans<m) 
		{
			cnt++;
        }
		else 
		{
			break;
		}
    }
     cout<<cnt;
}

void yiban()
{
	long long cnt=0;
	long long ans=0;
	long long cnt1=-1e18;
	for(int i=1;i<=n;i++)
	{
		cnt=1;
		ans=0;
		for(int j=i-1;j>=1;j--)
		{
			ans+=a[i]-a[j];
			if(ans<=m)
			{
				cnt++;
				cnt1=max(cnt,cnt1);
			}
			else break;
		}
	}
	cout<<cnt1;
}

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    int sum=0;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++)
    {
    	b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++)
    {
    	if(b[i]==b[i-1])sum++;
    }
    if(sum==n)teAB(a[2]-a[1]);
    else yiban();
    return 0;
}

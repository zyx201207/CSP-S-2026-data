#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt=1,cnt2,maxn=-1e18;
bool flag=0;
long long a[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i = 1;i<=n;i++)
	{
		cnt2++;
		if(flag!=0)
		{
			cnt++;
			sum=sum+a[i]-a[i-1];
			if(cnt2>2)
			{
				sum=sum+a[i]-a[i-2]-a[i-1]+a[i-2];
			}
			if(sum>m)
			{
				cnt--;
				maxn=max(maxn,cnt);
				i--;
				a[i]=0;
				a[i-1]=0;
				cnt=1;
				sum=0;
				flag=0;
				cnt2=0;
			}
		}
		else
		{
			flag=1;
		}
	}
	maxn=max(maxn,cnt);
	cout<<maxn;
	return 0;
}

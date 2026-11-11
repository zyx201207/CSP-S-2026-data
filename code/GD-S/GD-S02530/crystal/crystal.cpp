#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans=1,ch,num,cnt;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==0)
	{
		cout<<1;
		return 0;
	}
	long long ch=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(ch==a[i]-a[i-1])
			num++;
	if(num==n-2)
	{
		for(int i=n-1;i>=1;i--)
		{
			int dif=a[n]-a[i];
			m-=dif;
			if(m<0)
			{
				cout<<cnt;
				return 0;
			}
			cnt++;
		}
	}
	sort(a+1,a+n+1); 
	for(int i=2;i<=n;i++)
	{
		long long sum=1,tim=m;
		for(int j=i-1;j>=1;j--)
		{
			int dif=a[i]-a[j];
			tim-=dif;
			if(tim<0)
			{
				ans=max(ans,sum);
				break;
			}
			sum++;
		}
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
}

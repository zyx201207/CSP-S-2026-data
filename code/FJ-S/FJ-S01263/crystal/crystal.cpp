#include<bits/stdc++.h>
using namespace std;
long long a[5000005];
long long n,m;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>=5000)
	{
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		int x=a[2]-a[1];
		long long cnt=0;
		if(a[1]<=a[n])
		{
			for(int i=1;i<=n;i++)
			{
				int t=a[i];
				if((i-1)*t-(t-x+1)*(i-1)*0.5<=m)
				{
					cnt=i;
				}
				else
				{
					cout<<cnt;
					return 0;
				}
			}
		}
		else
		{
			long long ta[500005];
			for(int i=1;i<=n;i++)
			{
				ta[i]=a[n-i+1];
			}
			for(int i=1;i<=n;i++)
			{
				a[i]=ta[i];
			}
			for(int i=1;i<=n;i++)
			{
				int t=a[i];
				if((i-1)*t-(t-x+1)*(i-1)*0.5<=m)
				{
					cnt=i;
				}
				else
				{
					cout<<cnt;
					return 0;
				}
			}
		}
	}
	//cout<<endl<<666<<endl;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	//cout<<endl<<666<<endl;
	sort(a+1,a+n+1);
	//cout<<endl<<666<<endl;
	long long max_cnt=-1e9;
	long long tm=m;
	for(int i=n;i>=1;i--)
	{
		//cout<<endl<<666<<endl;
		long long t=a[i];
		long long cnt=0;
		for(int j=i;j>=1;j--)
		{
			if(tm>=t-a[j])
			{
				tm-=t-a[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		tm=m;
		//cout<<t<<' '<<max_cnt<<' '<<cnt<<endl;
		max_cnt=max(max_cnt,cnt);
	}
	cout<<max_cnt;
	return 0;
}

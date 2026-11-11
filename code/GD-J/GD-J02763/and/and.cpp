#include <bits/stdc++.h>
using namespace std;
long long n,m,ans,x,num[35],cnt;
priority_queue <long long,vector <long long>,greater<long long> > a;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>x;
		a.push(x);
		cnt=0;
		while (x)
		{
			if (x%2)
				num[cnt]++;
			cnt++;
			x/=2;
		}
	}
	for (int i=0;i<=29;i++)
		cout<<num[i]<<" ";
	cout<<endl;
	for (int i=30;i>=0;i--)
	{
		if (num[i]>=m)
		{
			for (int j=1;j<=n-num[i];j++)
			{
				x=a.top();
				cnt=0;
				while (x)
				{
					if (x%2)
						num[cnt]--;
					cnt++;
					x/=2;
				}
				a.pop();
			}
			n=num[i];
			ans+=pow(2,i);
			cout<<i<<" "<<ans<<" "<<num[i]<<endl;
		}
	}
	cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;

int a[500005],b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if (m==1)
	{
		cout << n;
	}
	else if (m==2)
	{
		int cnt1=0,cnt2=0;
		for (int i=1;i<=m;i++)
		{
			int ans=0;
			for (int j=j;i<=n;j++)
			{
				b[3]=a[i];
				if (b[3]==b[1])ans=1;
				else ans=2;
			}
			if (ans==1) cnt1++;
			else cnt2++;
		}
		cout << cnt1 << " " << cnt2;
	}
	else 
	{
		for (int t=1;t<=m;t++)
		{
			int cnt=1;
			for (int i=2;i<=n;i++)
			{
				if (a[i]!=a[i-1]) cnt++;
			
			}
			cout << cnt << " ";
		}
	}
	return 0;
}

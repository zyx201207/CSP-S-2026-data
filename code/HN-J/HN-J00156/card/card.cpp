#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[10005],cnt=0,sum=0;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=m;i++)
	{
		for(int i=1;i<=n;i++)
		{
			if(a[i]==a[i-1])
			{
				a[i]=0;
				a[i-1]=0;
			}
			if(a[i]!=0)
			{
				cnt++;
				cout << cnt;
			}
		}
	}
} 

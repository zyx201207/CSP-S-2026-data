#include <bits/stdc++.h>
using namespace std;
int n,m,s[500010],t[500010],r[500010];
int main()
{
	freopen("card.in","v", stdin);
	freopen("card.out","w", stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> s[i];
	}
	for(int _=1;_<=n;_++)
	{
		int l=0;
		for(int i=_;i<=n;i++)
		{
			bool ok=0;
			int l1=0;
			for(int j=1;j<=l;j++)
			{
				if(t[j]==s[i])
				{
					ok=1;
					l1=j;
					break;
				}
			}
			if(!ok)
			{
				l++;
				t[l]=s[i];
			}
			else
			{
				l=l1;
			}
		}
		for(int i=1;i<=l;i++)
		{
			r[t[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << r[i] << " ";
	}
	cout << '\n';
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],sam[1000001];
string a2;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int l = 1;
	cin>>n>>m;
	for(int i = 1;i <= n;i++)
	{
		cin>>a[i];
	}
	for(int i = l;i <= n;i++)
	{
		for(int j = l;j <= n;j++)
		{
			a2 += a[j];
			for(int c = l;c <= j;c++)
			{
				if(a2[j] == a2[c])
				{
					a2 = a2[c];
				}
			}
		}
		for(int i = 1;i <= m;i++)
		{
			sam[a2[i]]++;
		}
		l++;
	}
	for(int i = 1;i <= m;i++)
	{
		cout<<sam[i]<<" ";
	}
	return 0;
}

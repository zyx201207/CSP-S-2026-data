#include <bits/stdc++.h>
using namespace std;
int a[500005],b[500005],ma[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,x,l=0;
	cin >> n >> m;
	for (int i = 1;i<= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i<= n;i++)
	{
		l =0;
		for (int j = i;j<= n;j++)
		{
			for (int k = 1;k<= l;k++)
			{
				if (a[j] == b[k])
				{
					l = k-1;
					break;
				}
			}
			l++;
			b[l] = a[j];
			
		}
		for (int i = 1;i<= l;i++)
		{
			ma[b[i]]+=1;
		}
	}
	for (int i = 1;i<= m;i++)
	{
		cout << ma[i] << " ";
	}
 } 


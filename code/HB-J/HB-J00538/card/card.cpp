#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005],b[100005];
int s[200005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int se=0;
		memset(s,0,sizeof s);
		for(int j=i;j<=n;j++)
		{
			se++;
			s[se]=a[j];
			for(int k=1;k<se;k++)
			{
				if(s[k]==s[se])
				{
					for(int r=se;r>=k;r--)
					{
						s[r]=0;
						se--;
					}
					s[k]=a[j];
					se++;
					break;
				}
			}
		}
		for(int j=1;j<=se;j++)
		{
			b[s[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
	feropen("crystal.in",r,"stdin");
	feropen("crystal.out",w,"stdout");
	int n,m,c=0;
	cin >> n >> m;
	int a[n+1]{};
	for(int i=1;i<=n;i++)cin >> a[i];
	sort(a,a+n+1);
	for(int i=1;i<n;i++)
	{
		int s=m+a[i];
		for(int j=i+1;j<=n;j++)
		{
			s+=a[j];
			int q=s;
			q/=(j-i+1);
			for(int k=1;k<=n;k++)
			{
				if(q==a[k])
				{
					for(int l=i;l<=j;l++)
					{
						a[l]+=(q-a[l]);
					}
					int x=0;
					for(int l=1;l<=n;l++)
					{
						if(a[l]==a[k])x++;
					}
					c=max(c,x);
				}
			}
		}
	}
	cout << c;
	return 0;
}

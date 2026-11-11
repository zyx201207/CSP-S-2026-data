#include <bits/stdc++.h>
using namespace std;
const int N=500001;
int a[N];
int n,m,maxx=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if (n==1)
	{
		cout<<1;
		return 0;
	}
	for (int i=2;i<=n;i++)
	{
		int num=1;
		int g=m;
        for (int j=i-1;j>=1;j--)
        {
        	if (a[i]==a[j]) num++;
        	else if (a[i]-a[j]<=g)
        	{
        		num++;
        		g-=a[i]-a[j];
        		
			}
			else
			{
				cout<<max(maxx,num);
				return 0;
			}
		}
		maxx=max(maxx,num);	
	}
	cout<<maxx;
	return 0;
}

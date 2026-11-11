#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and1.in","r",stdin);
	freopen("and1.out","w",stdout);
	long long n,m;
	int mx,a[1005],t[1005];
	cin>>n>>m;
	for (int i=0;i <= n;i++)
	{
		cin>>a[i];
	}
	for (int i=0;i <= n;i++)
	{
		if (m == 2)
		{
			t[i]=a[i] and a[i+1];
			if (i != 0)
			{
				mx=max(t[i-1],t[i]);
			}	
		}
	}
	cout<<mx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

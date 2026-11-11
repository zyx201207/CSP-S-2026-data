//GZ-J00060  务川仡佬族苗族自治县县庆中学 田星辰 
#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n,m,a[100086],ans[100086];
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	if(n==m)
	{
		int x=a[1];
		for(int i=2;i<=n;i++)
		{
			x=x&a[i];
		}
		cout << x;
		return 0;
	}
	if(m==1)
	{
		int y=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]>y) y=a[i];
		}
		cout << y;
		return 0;
	}
	int man=0;
	for(int i=1;i<=n;i++)
	{
		ans[i]=a[i+1];
		for(int j=1;j<=n;j++)
		{
			if(j!=i)
			{
				ans[i]=ans[i]&a[j];
			}
		}
		if(ans[i]>man)
		{
			man=ans[i];
		}
	}
	cout << man;
	return 0;
	fclose(stdin);
	fclose(stdout);
}



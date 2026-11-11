#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200500],ans = -1,t;
int main()
{
	freopen("and.in","r",stdin);
	feropen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		t = a[i];
		for(int j=1;j<=n;j++)
		{
			for(int k=j;k<=j+m-1;k++)
			{
				t = t&a[k];
			}
			ans = max(ans,t);
			t = a[i];
		}
	}
	cout<<ans;
	return 0;
}

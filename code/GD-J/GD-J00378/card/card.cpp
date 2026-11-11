#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card,in","r",stdin);
	freopen("card,out","w",stdout);
	long long a[10005],n,m,i;
	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	cout<<m;
	for(i=n;i>=n/2;i--)
	{
		cout<<a[i]<<" ";
	}
}

#include <bits/stdc++.h>
using namespace std;
long long a[1000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
    sort(a+1,a+n+1);
	int ans=a[n];
    for(int i=1;i<m;i++)
    {
    	ans=ans&a[n-i];
	}
	cout<<ans;
}

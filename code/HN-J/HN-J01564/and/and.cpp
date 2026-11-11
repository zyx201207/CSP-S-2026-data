#include <bits/stdc++.h>
using namespace std;
int n,m,a[1000005],b[1000005],cnt=-1;
int main()
{
	
	freopen("and.in","r",stdin);
	freopen("add.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		if((a[i]&a[i+1])>cnt)
		{
			cnt=(a[i]&a[i+1]);
		}
	}
	cout<<cnt;
}

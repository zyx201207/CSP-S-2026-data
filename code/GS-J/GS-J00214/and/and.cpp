#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int m,n;
	int cnt=0,b=0;
	cin>>m>>n;
	for(int i=0;i<=n+1;i++)
	{
		cin>>a[i];

	}
	for(int j=1;j<=m;j++)
		{
		b=a[j]&&a[j+1];	
		if(b>=cnt)
	{
		cnt=b;
	}
		}
		

	cout<<cnt;


	return 0;
}

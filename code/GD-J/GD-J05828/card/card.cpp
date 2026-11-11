#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int sum[500050]{0};
	cin>>n>>m;
	int cnt=n;
	int a[500050];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m=1)
	{
		if(n%2==0)
		{
			cout<<n/2;
		}
		else
			cout<<n/2+1;
	}
	
	return 0;
}

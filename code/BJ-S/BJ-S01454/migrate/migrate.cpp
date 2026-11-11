#include <bits/stdc++.h>
using namespace std;
const int N=1e7+5;
int c,t,n,m,a[N],b[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t>>n>>m;
	for(int i =1;i<=t;i++)
	{
		cin>>n;
		for(int i =1;i<=n;i++)
		{
			cin>>a[i];
			if(a[i]-a[i-1]>m)
			{
				cout<<0;
				return 0;
			}
		}
	}
	if (n<=3) cout<<1;
	else if((n-1)%m==0)
	{
		if(((n/m)-2)<0) cout<<0;
		else cout<<(n/m)-2;
	}
	else if((n-1)%m==(m-1)) cout<<(n/m)-1;
	return 0;
}

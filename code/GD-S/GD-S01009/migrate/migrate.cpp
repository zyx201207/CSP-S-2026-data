#include<bits/stdc++.h>
using namespace std;
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5
*/
int a[2000010];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			int l = a[i]+2*d-1;
			int *r = lower_bound(a,a+n,l);
			if(*r == l) ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}

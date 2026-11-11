#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,t,n,d,x[200086];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		int sum[200086],ans;
		for(int i=1;i<=n;i++) cin>>x[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=d;j++)
			{
				int w=upper_bound(x+1,x+1+n,i+j)-x-1;
				if(x[w]==i+j) sum[i+j]++;
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(sum[i]==2) ans++;
		}
		cout<<ans/2<<endl;
	}
	return 0;
}

/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

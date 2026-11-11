#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,_,n,k,a[2000005];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>_;
	while(_--)
	{
		cin>>n>>k;
		for(int i=1;i<=n;i++) cin>>a[i];
		bool ok=1;
		for(int i=3;i<=n;i++)
		{
			if(a[i]-a[i-1]!=a[i-1]-a[i-2]){ok=0;break;}
		}
		if(ok)
		{
			int cha=a[2]-a[1],e=k/cha,ans=0;
			if(e==2)
			{
				for(int i=1;i<e;i++)
				{
					int len=e+i+1;
					ans+=n-len+1;
				}
			}
			cout<<ans<<'\n';
			continue;
		}
		cout<<"0\n";
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

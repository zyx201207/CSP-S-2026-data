#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int c,t;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--)
	{
		int n,m,a[N];
		map<int,int> ma;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			ma[a[i]]=1;
		}
		int ans=0;
		for(int i=1;i<n;i++)
		{
			for(int j=1;(a[i]+(j*m))<=a[n];j++)
			{
				int zhizhi=a[i]+(j*m);
				if(ma[zhizhi]==1)
				{
					int mid;
					if(m%2!=0) mid=(m+1)/2;
					else mid=m/2;
					for(int k=mid;k<m;k++)
					{
						if(ma[zhizhi+k]==1) ans++;
					 } 
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/

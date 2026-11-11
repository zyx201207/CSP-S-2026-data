#include <bits/stdc++.h>
using namespace std;
const long long N=1e18+5;long long n,d;
long long c,t,ans=0,a[2000005];

bool check(int l,int r)
	{
	long long less_step=N;
	long long least_step;
	for (long long i=l;i<=r;i++)
		{
		if (i%2==1) return 1;
		}
	return 0;
	}
	
int main ()
	{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while (t--)
		{
		ans=0;
		cin>>n>>d;
		for (int i=1;i<=n;i++)
			cin>>a[i];
		for (int i=1;i<n;i++)
			{
			for (int j=i+1;j<=n;j++)
				{
				if (abs(a[i]-a[j])<=d || abs(i-j)<3) continue;
				else 
					if (check(i,j)) ans++;
				}
			}
		cout<<ans<<endl;
		}
	return 0;
	}

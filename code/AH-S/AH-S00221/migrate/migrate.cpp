#include<bits/stdc++.h>
#define int long long
using namespace std;
bool pd1;
int ans;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",sdtout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i];
			if(i>2&&x[i]-x[i-1]!=x[i-1]-x[i-2])pd1=true;
		}
		if(!pd1)
		{
			int k=(d)/(x[2]-x[1]);
			n-k-1;
			for(int i=1;i<=n/k;i++)
				ans+=max(n-k*i-1,0);
		}
		else ans=n*n/4;
		cout<<ans<<endl;
	}
	return 0;
}

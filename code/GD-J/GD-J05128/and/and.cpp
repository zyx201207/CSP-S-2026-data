#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200010],f[200010],mx,v[200010][35],t[35],ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		mx|=a[i];
		for(int j=0;j<30;j++)
			if(a[i]&(1<<j))
				v[i][j]=1,t[j]++;
	}
	for(int i=29;i>=0;i--)
	{
		if(t[i]<m)	continue;
		ans+=(1<<i);
		for(int j=1;j<=n;j++)
		{
			if(f[j])	continue;
			if(!v[j][i])
			{
				f[j]=1;
				for(int k=0;k<30;k++)
					if(a[j]&(1<<k))
						v[j][k]=0,t[k]--;
				continue;
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}

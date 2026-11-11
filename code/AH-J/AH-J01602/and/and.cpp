#include<bits/stdc++.h>
using namespace std;
int a[200005],b[200005][35],vis[200005];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n,m,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int x=a[i],y=0;
		while(x)
		{
			b[i][++y]=x%2;
			x/=2;
		}
	}
	b[0][0]=1;
	for(int i=1;i<=30;i++)
		b[0][i]=b[0][i-1]*2;
	for(int i=30;i>=1;i--)
	{
		int k=0;
		for(int j=1;j<=n;j++)
			k+=b[j][i]*(1-vis[j]);
		if(k>=m)
		{
			for(int j=1;j<=n;j++)
				if(b[j][i]==0)
					vis[j]=1;
			s+=b[0][i-1];	
		}
	}
	cout<<s;
	return 0;
}


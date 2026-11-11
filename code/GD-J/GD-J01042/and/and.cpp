#include<bits/stdc++.h>
using namespace std;
bool f[200005][35];
long long n,m,x,a[200005],t,b[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		t=a[i];
		for(int j=30;j>=0;j--) if(t>=(1<<j)) t-=(1<<j),f[i][j]=1;
	}
	for(int i=30;i>=0;i--)
	{
		long long ans=0;
		for(int j=1;j<=n;j++) if(f[j][i]==1) ans++;
		if(ans>=m)
		{
			x=i;
			break;
		}
	}
	t=0;
	for(int i=1;i<=n;i++) if(f[i][x]==1) t++,b[t]=a[i];
	if(t==m)
	{
		long long k=b[1]&b[2];
		for(int i=3;i<=t;i++) k=k&b[i];
		cout<<k;
	}
	else
	{
		sort(b+1,b+t+1);
		long long k=1,p=-1;
		for(int i=1;i<=t;i++)
		{
			if(b[i]!=b[i-1])
			{
				if(k>=m) p=max(p,b[i-1]);
				k=1;
			}
			else k++;
		}
		if(k>=m) p=max(p,b[t]);
		if(p>=0) cout<<p;
		else
		{
			while(1)
			{
				for(int i=x;i>=0;i--)
				{
					long long ans=0;
					for(int j=1;j<=n;j++) if(f[j][i]==1) ans++;
					if(ans>=m)
					{
						x=i;
						break;
					}
				}
				t=0;
				for(int i=1;i<=n;i++) if(f[i][x]==1) t++,b[t]=a[i];
				if(t==m || x==0) break;
			}
			long long k=b[1]&b[2];
			for(int i=3;i<=t;i++) k=k&b[i];
			cout<<k;
		}
	}
	return 0;
}

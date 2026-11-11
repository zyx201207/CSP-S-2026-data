#include<bits/stdc++.h>
using namespace std;
int n,m,a[200020],f[200020],ans=0,k=-1e9;
int g[200020][50];
bool flag;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		cin>>a[i];
		while(a[i])
		{
			g[i][cnt]=a[i]%2;
			a[i]/=2;
			cnt++;
		}
		k=max(k,cnt);
	}
	for(int i=k-1;i>=0;i--)
	{
		int cnt=0;
		for(int j=1;j<=n;j++)
		{
			if(g[j][i] and !f[j])
				cnt++;
		}
		if(cnt>=m)
		{
			ans+=pow(2,i);
			flag=1;
		}
		for(int j=1;j<=n;j++)
			if(!g[j][i] and flag)
				f[j]=1;	
	}
	cout<<ans;
	return 0;
}

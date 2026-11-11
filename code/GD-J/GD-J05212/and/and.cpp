#include<bits/stdc++.h>
using namespace std;
int n,m,x,b[200005],a[200005][40],cnt,sum=0,vis[200005],s,tmp=0,ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		b[i]=x;
		cnt=0;
		while(x!=0)
		{
			cnt++;
			a[i][cnt]=x%2;
			x/=2;
		}
		sum=max(cnt,sum);
	}
	for(int i=sum;i>=1;i--)
	{
		s=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==0&&a[j][i]==1)
			{
				s++;
			}
		}
		if(s>=m)
		{
			for(int j=1;j<=n;j++)
			{
				if(a[j][i]==0)
				{
					vis[j]=1;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			if(tmp==0)
			{
				ans=b[i];
			}
			else
			{
				ans=(ans&b[i]);
			}
			tmp++;
			if(tmp==m)
			{
				break;
			}
		}	
	}
	cout<<ans;
	return 0;
}

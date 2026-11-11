#include<bits/stdc++.h>
using namespace std;
int n,m,d,q,a[500005],b[501][500001],c[501][501],k,e,frw,tow,ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=500;i++)
	{
		for(int j=1;j<=500;j++)
		{
			c[i][j]=2147483647;
		}
	}
	for(int i=1;i<=n;i++)
	{
		cin>>k;
		while(k--)
		{
			cin>>e;
			cin>>b[i][e];
			for(int j=1;j<i;j++)
			{
				if(c[j][i]>(b[i][e]+b[j][e])&&b[i][e]>0&&b[j][e]>0)
				{
					c[j][i]=(b[i][e]+b[j][e]);
					c[i][j]=(b[i][e]+b[j][e]);
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int k=1;k<=n;k++)
		{
			if(c[i][k]<2147483647)
			{
				for(int l=1;l<=n;l++)
				{
					if(c[i][l]<2147483647)
					{
						c[k][l]=min(c[k][l],c[i][k]+c[i][l]);
						c[l][k]=c[k][l];
					}
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		cin>>frw>>tow;
		ans=2147483647;
		for(int j=1;j<=n;j++)
		{
			if(b[j][frw]>0&&b[j][tow]>0)
			{
				ans=min(ans,(a[frw]+a[tow]+b[j][frw]+b[j][tow]));
			} 
			else if(b[j][frw]>0)
			{
				for(int k=1;k<=n;k++)
				{
					if(b[k][tow]>0)ans=(min(ans,c[k][j]+a[frw]+a[tow]+b[j][frw]+b[k][tow])>0?min(ans,c[k][j]+a[frw]+a[tow]+b[j][frw]+b[k][tow]):ans);
				}
			}
		}
		cout<<ans<<endl;
	}
	
	return 0;
}

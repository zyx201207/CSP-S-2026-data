#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],t[300005];
int main()
{
	freopen("hud.in","r",stdin);
	freopen("hud.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(t,0,sizeof(t));
		int y=1;
		for(int j=i;j<=n;j++)
		{
			if(t[a[j]]==0)
			{
				t[a[j]]=y;
				y++;
			}
			else
			{
				y=t[a[j]];
				for(int x=1;x<=m;x++)
				{
					if(t[x]>=y)
					    t[x]=0;
				}
				t[a[j]]=y;
				y++;
			}
		}
		for(int x=1;x<=m;x++)
		{
			if(t[x]!=0)
			{
				b[x]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<endl;
	return 0;
}

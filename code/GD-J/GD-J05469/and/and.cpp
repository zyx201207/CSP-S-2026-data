#include<bits/stdc++.h>
using namespace std;
int main()
{
	//freopen("and.in","r",stdin);
	//freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+1];
	bool vis[n+1];
	memset(vis,true,sizeof(vis));
	int ma=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		int cnt=1;
		while(cnt<=a[i])
		{
			cnt*=2;
		}
		cnt/=2;
		ma=max(ma,cnt);
	}
	int ans=0;
	for(int i=ma;i>=1;i/=2)
	{
		int num=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]&&a[j]/i>=1)
			{
				num++;
				a[j]-=i;
				//cout<<"Y";
			}
			else
			{
				vis[j]=false;
				//cout<<"N";
			}
		}
		//cout<<endl;
		for(int j=1;j<=n;j++)
		{
			vis[j]=(num>=m)?vis[j]:1;
		}
		if(num>=m)
		{
			ans+=i;
		}
	}
	cout<<ans;
	return 0;
}

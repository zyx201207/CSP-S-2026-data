#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],b[205],c[200005][205],ans=0,vis[200005];
vector<int> v[205];
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		int num=a[i],num2=0;
		while(num)
		{
			num2++;
			b[num2]+=num%2;
			if(num%2==1)
			{
				v[num2].push_back(a[i]);
			}
			num/=2;
		}
		
	}
	for(int i = 205;i>=1;i--)
	{
		if(b[i]>=m)
		{
			int num6=1;
			for(int j = 2;j<=i;j++)
			{
				num6*=2;
			}
			ans+=num6;
			for(int j = 0;j<v[i].size();j++)
			{
				int num=v[i][j],num2=0;
				while(num)
				{
					num2++;
					c[j][num2]+=num%2;
					
					num/=2;
				}
				vis[j]=1;
			}
			int num3=i-1;
			while(num3>0)
			{
				int num4=0;
				for(int j = 0;j<v[i].size();j++)
				{
					if(vis[j]==1)
					{
						num4+=c[j][num3];
					}
					
				}
				if(num4>=m)
				{
					int num7=1;
					for(int j = 2;j<=num3;j++)
					{
						num7*=2;
					}
					ans+=num7;
					for(int j = 0;j<v[i].size();j++)
					{
						if(c[j][num3]==0)
						{
							vis[j]=0;
						}
					}
				}
				num3--;
			}
			break;
		}
		
	}
	cout<<ans<<'\n';
	return 0;
}

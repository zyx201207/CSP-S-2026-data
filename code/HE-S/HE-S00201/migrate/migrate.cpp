#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000006];
signed main()
{
	ios::sync_with_stdio(false);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
//		if(c<=2)
		{
			int A=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=i+1;j<=n;j++)
				{
					int mx=0,lst=i;
					for(int k=i;k<j;)
					{
						while(k<j&&a[k+1]-a[lst]<=d)
						{
							k++;
						}
						if(k==lst)break;
						lst=k;
						mx++;
					}
					if(mx==0)continue;
					queue<pair<int,int>>q;
					q.push({i,0});
					int ans=0;
					while(!q.empty())
					{
						auto x=q.front();
						q.pop();
						if(x.second>mx)continue;
						if(x.first==j&&x.second==mx)
						{
							ans++;
							continue;
						}
						int k=x.first+1;
						while(k<=j&&a[k]-a[x.first]<=d)
						{
							q.push({k,x.second+1});
							k++;
						}
					}
					if(ans==2)A++;
//					if(ans==2)
//					{
//						cout<<i<<" "<<j<<endl;
//					}
				}
			}
			cout<<A<<'\n';
		}
	}
}

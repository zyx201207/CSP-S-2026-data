#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c<=10)
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,d;
			cin>>n>>d;
			int a[n+1];
			for(int i=1;i<=n;i++)
			cin>>a[i];
			int b[n+1];
			int c[n+1];
			int ans=0;
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				b[j]=0x3f3f3f3f3f3f3f3f;
				b[i-1]=0;
				for(int j=0;j<=n;j++)
				c[j]=1;
				queue<pair<int,int>>q;
				q.push({i,0});
				while(!q.empty())
				{
//					cout<<q.front().first<<' '<<q.front().second<<endl;
					if(b[q.front().second]+1>b[q.front().first])
					{
						q.pop();
						continue;
					}
					if(b[q.front().second]+1<b[q.front().first])
					{
						b[q.front().first]=b[q.front().second]+1;
						c[q.front().first]=c[q.front().second];
					}
					else if(b[q.front().second]+1==b[q.front().first])
					{
						c[q.front().first]+=c[q.front().second];
						if(c[q.front().first]>99)
						c[q.front().first]=99;
					}
					for(int j=q.front().first+1;j<=n;j++)
					{
						if(a[j]-a[q.front().first]<=d)
						q.push({j,q.front().first});
					}
					q.pop();
				}/*
				for(int i=1;i<=n;i++)
				{
					if(b[i]==0x3f3f3f3f3f3f3f3f)
					cout<<-1;
					else
					cout<<b[i];
					cout<<' ';
				}
				cout<<endl;
				for(int i=1;i<=n;i++)
				{
					cout<<c[i]<<' ';
				}
				cout<<endl<<endl;*/
				for(int j=i+1;j<=n;j++)
				if(c[j]==2)
				ans++;
			}
			cout<<ans<<endl;
		}
	}
	else
	{
		int t;
		cin>>t;
		while(t--)
		{
			int n,d;
			cin>>n>>d;
			int a[n+1];
			for(int i=1;i<=n;i++)
			cin>>a[i];
			int k=d/(a[2]-a[1]);
			k=k*2-1;
			int ans=0;
			if(k!=1)
			ans=n-k;
			cout<<ans<<endl;
		}
	}
	return 0;
}
/*
0 1
4 2
1 2 3 4
*/

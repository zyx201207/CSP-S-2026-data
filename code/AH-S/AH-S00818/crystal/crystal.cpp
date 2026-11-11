#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,sum;
int a[500005];
queue<int> q;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	q.push(a[1]);
	int ans=0;
	for(int i=2;i<=n;i++)
	{
		sum=max(sum,(int)q.size());
		if(a[i]==q.back())
		{
			q.push(a[i]);
		}
		else
		{
			if(!q.empty()&&ans+(a[i]-q.back())*q.size()<=m)
			{
				ans+=(a[i]-q.back())*q.size();
				q.push(a[i]);
			}
			else
			{
				if(a[i]-q.front()>m)
				{
					while(!q.empty())
					{
						q.pop();
					}
					ans=0;
					q.push(a[i]);
					continue;
				}
				while(!q.empty()&&ans+(a[i]-q.back())*q.size()>m)
				{
					int x=q.front();
					q.pop();
					ans-=q.back()-x;
				}
				if(!q.empty())
				{
					ans=ans+(a[i]-q.back())*q.size();
					q.push(a[i]);
				}
			}
		}
	}
	sum=max(sum,(int)q.size());
	cout<<sum<<"\n";
	return 0; 
}
/*
*/


#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,cnt,k,ans,x;
queue<int>q1;
queue<int>q2;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>x;
		q1.push(x);
	}
	for(int i=29;i>=0;i--)
	{
		cnt=0;
		k=q1.size();
		while(k--)
		{
			int u=q1.front();
			if(u&(1<<i))
				q2.push(u),cnt++;
			q1.push(q1.front());
			q1.pop();
		}
		if(cnt>=m)
		{
			while(!q1.empty())
				q1.pop();
			while(!q2.empty())
			{
				q1.push(q2.front());
				q2.pop();
			}
			ans|=(1<<i);
		}
		else
		{
			while(!q2.empty())
				q2.pop();
		}
	}
	cout<<ans<<'\n';
	return 0;
}

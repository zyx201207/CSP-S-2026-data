#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,x[1145140],ans;
struct node
{
	int step,cnt;
};
int main()
{
freopen("migrate.in","r",stdin);
freopen("migrate.out","w",stdout);
cin>>c>>t;
while(t--)
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	sort(x+1,x+n+1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			queue<node> q;
			q.push({i,0});
			while(!q.empty())
			{
				node tmp=q.front();
				if(tmp.step==j)
				{
					break;
				}
				for(int i=tmp.step+1;;i++)
				{
					if(x[i]-x[tmp.step]>d)
					{
						break;
					}
					q.push({i,tmp.cnt+1});
				}
				q.pop();
			}
			int cnt=0;
			int awa=q.front().cnt;
			while(!q.empty()&&q.front().cnt==awa)
			q.pop(),cnt++;
			if(cnt==2)
			ans++;
		}
	}
	cout<<ans<<endl;
}
return 0;
}


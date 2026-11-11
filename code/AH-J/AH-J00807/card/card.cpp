#include<cstdio>
#include<iostream>
#include<queue>
#include<vector>
#include<stack>
#include<string>
#include<cstring>
using namespace std;
int ans[100086],cnt[100086];
queue <int> q;
queue <int> cd;
stack <int> fcd;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	stack <int> s;
	int n,m,cdi=0,sum=0;
	cin>>n>>m;
	sum=n;
	for(int i=1;i<=n;i++)
	{
		int u;
		cin>>u;
		q.push(u);
	}
	while(!q.empty())
	{
		cd.push(q.front());
		q.pop();
	}
	while(sum!=0)
	{
		while(!q.empty())
		{
			for(int i=1;i<=cdi;i++)
			{
				q.push(fcd.top());
				fcd.pop();
			}
			memset(cnt,0,sizeof(cnt));
			if(cnt[q.front()])
			{
				while(s.top()!=q.front())
				{
					while(fcd.top()!=s.top())
					{
						cd.push(fcd.top());
						fcd.pop();
					}
					fcd.pop();
					while(!cd.empty())
					{
						fcd.push(cd.front());
						cd.pop();
					}
					s.pop();
					sum--;
				}
				s.pop();
				sum--;
				cnt[q.front()]=0;
				q.pop();
			}
			s.push(q.front());
			q.pop();
			cnt[q.front()]=1;
		}
		s.pop();
		while(!s.empty())
		{
			ans[s.top()]++;
			fcd.push(s.top());
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<endl;	
	}
	return 0;
}

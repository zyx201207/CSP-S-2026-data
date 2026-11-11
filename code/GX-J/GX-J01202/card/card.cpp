#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<map>
#include<stack>
#include<queue>
using namespace std;
stack<int> q;
queue<int> s,a;
int n,m,d[300001],b[300001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s.push(x);
	}
	while(!s.empty())
	{
		int len=s.size();
		q.push(s.front());
		b[s.front()]++;
		s.pop();
		for(int i=2;i<=len;i++)
		{
			int x=s.front();
			q.push(x);
			a.push(x);
			b[x]++;
			s.pop();
			if(b[x]==2)
			{
				b[x]--;
				q.pop();
				while(q.top()!=x)
				{
					b[q.top()]--;
					q.pop();
				}
			}
		}
		while(!q.empty())
		{
			d[q.top()]++;
			b[q.top()]--;
			q.pop();
		}
		while(!a.empty())
		{
			s.push(a.front());
			a.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<d[i]<<" ";
	return 0;
}

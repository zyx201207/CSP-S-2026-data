#include <bits/stdc++.h>
using namespace std;
const int N = 2 * 100010;

long long cnt[N];

void card(queue<int> qu)
{
	stack<int> sk;
	set<int> st;
	while(!qu.empty())
	{
		int sz = st.size();
		st.insert(qu.front());
		if(st.size() == sz)
		{
			while(sk.top() != qu.front() && !sk.empty())
			{
				sk.pop();
			}
			sk.pop();
			sk.push(qu.front());
		}
		else sk.push(qu.front());
		qu.pop();
	}
	while(!sk.empty())
	{
		cnt[sk.top()]++;
		sk.pop();
	}
}

int a[N];
queue<int> q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	
	for(int i = 1;i<=n;i++)
	{
		int x;
		cin>>x;
		q.push(x);
	}
	
	while(!q.empty())
	{
		card(q);
		q.pop();
	}
	
	for(int i = 1;i<=m;i++) cout<<cnt[i]<<' ';
	
	return 0;
}

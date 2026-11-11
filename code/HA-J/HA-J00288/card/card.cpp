#include<bits/stdc++.h>
using namespace std;
int n,m,x;
int po;
queue<int> a,q;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	po = n;
	while(n--)
	{
		cin>>x;
		a.push(x);
	}
	while(1>0)
	{
		for(int i = 1;i<=po;i++)
		{
			if(!a.empty())
			{
				int u = a.front();
				a.pop();
				q.push(u);
				if(q.count(u))
				{
					while(1>0)
					{
						if(!q.empty() and q.size()>1){
							int o = q.front();
							q.pop();
							a.push(o);
						}	
					} 
				}
			} 
		else
		{
			break;
		}
	}
	return 0;
} 

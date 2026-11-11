#include<bits/stdc++.h>
using namespace std;
stack<int> p;
stack <int>q;
int n,m,a[1000];
int main()
{
	freopen("Ö½ÅÆÓÎÏ·£¨card£©.in","r",stdin);
	freopen("Ö½ÅÆÓÎÏ·£¨card£©.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) 
	{
		int x;
		cin>>x;
		p.push(x);
	}
	for(int i=1;i<=n;i++)
	{
		int b[1000];
		for(int j=1;j<=p.size();j++)
		{
			if(b[p.top()]==0)
			{
			q.push(p.top());	
			p.pop();
			}
			if(b[p.top()]!=0)
			{
				while(q.top()!=p.top())
				{
					q.pop();
				}
				p.pop();
			}
		}
		while(q.size()>0)
		{
			a[q.top()]++;
			p.push(q.top());
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)cout<<a[i]<<" ";
	return 0;
 } 

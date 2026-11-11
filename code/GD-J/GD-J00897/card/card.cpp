#include<bits/stdc++.h>
using namespace std;
long long a[500005],s,b[500005];
int n,m;
int main(){ 
	freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);	
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
	    stack<int> q;
		map<int,bool> p;
		for(int j=i;j<=n;j++)
		{
		    if(p[a[j]])
		    {
		    	while(!q.empty()&&q.top()!=a[j])
				{
					p[q.top()]=false;
					q.pop();
				}
				q.pop();
			}
			 p[a[j]]=true;
			q.push(a[j]); 
		}
		while(!q.empty())
		{
			b[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<b[i]<<" ";
	}
	return 0;
} 

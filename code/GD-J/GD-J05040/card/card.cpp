#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	long n,m;
	cin>>n>>m;
	long cards[n];
	for(long i=0;i<n;i++)
	{
		cin>>cards[i];
	}
	long anum[m];
	memset(anum,0,sizeof(anum));
	for(long i=0;i<n;i++)
	{
		bool app[m];
		memset(app,false,sizeof(app));
		stack<long> q;
		for(long j=i;j<n;j++)
		{
			if(app[cards[j]-1])
			{
				while(q.top()!=cards[j])q.pop();
				app[cards[j]-1]=true;
			}
			else
			{
				q.push(cards[j]);
				app[cards[j]-1]=true;
			}
			
		}
		while(!q.empty())
		{
			anum[q.top()-1]++;
			q.pop();
		}
	}
	for(long i=0;i<m;i++) cout<<anum[i]<<" ";
	cout<<endl;
	return 0;
} 

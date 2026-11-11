#include<bits/stdc++.h>
using namespace std;
int Used[300100],a[500100],d[300100];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);	
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int t=1;t<=n;t++)
	{
		queue<int> p;
		memset(Used,0,sizeof(Used));
		for(int i=1;i<=n;i++)
		{
			if(i<t) 
				continue;
			bool flag=false;
			if(Used[a[i]]==1)
			{
				queue<int> q;
				while(!p.empty())
				{
					if(p.front()==a[i])
					{
						flag=true;
						p.pop();
					}
					else if(flag==false)
					{
						q.push(p.front());
						p.pop(); 
					}
					else
					{
						Used[p.front()]=0;
						p.pop();
					}	
				}
				swap(p,q);
			}
			p.push(a[i]);
			Used[a[i]]=1;			
		}
		while(!p.empty())
		{
			d[p.front()]++;
			p.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<d[i]<<" ";
	cout<<endl; 
	return 0;
}


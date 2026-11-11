#include<bits/stdc++.h>
using namespace std;
const int N=3*100000+100;
int e[N];
int b[N];
int ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>e[i];
	} 
	deque<int> q;
	for(int l=1;l<=n;l++)
	{
		q.clear();
		memset(b,0,sizeof(b)); 

		for(int i=l;i<=n;i++)
		{
			int n_c=e[i];
			if(b[n_c]==0)
			{
				b[n_c]=1;
				q.push_back(n_c);
			}
			else
			{
				while(q.size()&&q.back()!=n_c)
				{
					b[q.back()]=0;
					q.pop_back();
				}
			}
		}
		for(auto v:q)
		{
			ans[v]++; 
		}
		
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}

	return 0;
 } 

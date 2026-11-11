#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],goes[300005];
int has[300005]={0};
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	stack <int> s;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(has,0,sizeof(has));
		for(int j=i;j<=n;j++)
		{
			if(has[a[j]]==1)
			{
				int siz=s.size();
				for(int l=1;l<=siz;l++)
				{
					int to=s.top();
					if(to==a[j]) break;
					s.pop();
				}
			}
			else s.push(a[j]),has[a[j]]=1;
		}
		while(!s.empty())
		{
			int l=s.top();
			goes[l]++;
			s.pop();
		}
		
	}
	for(int i=1;i<=m;i++) cout<<goes[i]<<" ";
	return 0;
}

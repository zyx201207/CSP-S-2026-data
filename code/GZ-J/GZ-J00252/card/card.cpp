//GZ-J00252 贵阳市第十七中学 吴芸智
#include<bits/stdc++.h>
using namespace std;
stack<int> q;
int const N=3e5+5;
int f[N],t[N],a[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,r=1;
	cin>>n>>m;
	int w=n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	while(w--)
	{
		memset(f,0,sizeof(f));
		for(int i=r;i<=n;i++)
		{
			if(f[a[i]]==1)
			{
				int y;
				while(y!=a[i])
				{
					int y=q.top();
					q.pop();
				}
					q.push(a[i]);
			}
			else
			{
				q.push(a[i]);
			    f[a[i]]=1;
			}
		}
		while(q.empty()!=1)
		{
		 	int v=q.top();
			q.pop();
			t[v]++;
		}
	    r++;
    }
    for(int i=1;i<=m;i++)
    {
    	cout<<t[i]<<' ';
	}
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
int n,m;
struct edge
{
	int id,sum;
}edge[maxn];
bool cmp(struct edge &x,struct edge &y)
{
	if(x.sum==y.sum) 
	{
		return x.id>y.id;
	}
	return x.sum>y.sum;
}
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>edge[i].id;
	    int je=edge[i].id;
		while(je!=0)
		{
			if(je%2==1)
			{
				edge[i].sum++;
			}
			je/=2;
		} 	    	
	}
	sort(edge+1,edge+n+1,cmp);
	int ans=edge[1].id;
	for(int i=2;i<=m;i++)
	{
		if(ans&edge[i].id!=0)
		{
			ans=ans&edge[i].id;
		} 
		else
		{
			m++;
		}
	}
	cout<<ans<<endl;
	return 0;
}

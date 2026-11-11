#include<bits/stdc++.h>
using namespace std;
int a[500005],b[500005],ans[500005];
int n,m,x,y;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]++;
	}
	
    for (int i=1;i<=n;i++)
    {
    	b[a[i]]--;
    	if (y==0||b[x]==0)
    	ans[a[i]]=i;
    	else
    	ans[a[i]]+=(i-y);
    	if (b[a[i]]>0)
    	{
    		x=a[i];
    		y=i;
		}
		else
		{
			if (b[x]==0)
			{
				x=0;
				y=0;
			}
		}
	}
	for (int i=1;i<=m;i++)
	cout<<ans[i]<<" ";
	return 0;
}

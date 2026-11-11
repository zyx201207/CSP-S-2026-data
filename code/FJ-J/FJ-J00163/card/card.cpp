#include <bits/stdc++.h>
using namespace std;
int n,m,pos;
int ans[300005],a[500005];
bool vis[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(!vis[a[i]])
		{
			vis[a[i]]=true;
		}
		else{
			for(int j=1;j<=i;j++)
			{
				if(a[i]==a[j])
				{
				    pos=j;
					break;			
				}
			}
			for(int k=pos;k<=i;k++)
			     a[k]=-1;
			a[pos]=a[i];
		}
		for(int l=1;l<=pos;l++)
		{
			ans[a[l]]++;
		}
	}
	for(int i=1;i<=m;i++)
	    cout<<ans[i]<<" ";
	return 0;
}

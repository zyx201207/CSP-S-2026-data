#include<bits/stdc++.h>
using namespace std;
int n,m,ans[500005],a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int tmp=i;
		for(int j=i;j<=n;j++)
		{
			for(int k=j+1;k<=n;k++)
			{
				if(a[k]==a[j])
				{
					j=k-1;
					tmp=k;
					break;
				}
			}
		}
		//cout<<tmp<<endl;
		for(int j=tmp;j<=n;j++)
		{
			//cout<<a[j];
			ans[a[j]]+=1;

		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[m]<<' ';
	}
	return 0;
}

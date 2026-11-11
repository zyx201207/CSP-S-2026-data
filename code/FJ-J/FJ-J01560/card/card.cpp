#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],tong[300005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int table[500005]={},q=0;
		for(int j=i;j<=n;j++)
		{
			int f=0;
			for(int k=1;k<=q;i++)
			{
				if(table[k]==a[j])
				{
					q=k;
					f=1;
					break;
				}
			}
			if(f==0)table[++q]=a[j];
		}
		for(int j=1;j<=q;j++)
		{
			tong[table[j]]++;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int n,m,a[700000];
int p[700000];
int ans[700000];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int sum=0;
		for(int j=i;j<=n;j++)
		{
			for(int k=1;k<=sum;k++)
				if(p[k]==a[j])
				{
					for(int q=k;q<=sum;q++)
						p[q]=0;
					break;
				}
			p[sum+1]=a[j];
			sum++;
		}
		for(int j=1;j<=sum;j++)
		{
			ans[p[j]]++;
			p[j]=0;
		}			
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}

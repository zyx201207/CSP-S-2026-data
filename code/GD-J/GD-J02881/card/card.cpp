#include<bits/stdc++.h>
using namespace std;
int a[114514];
int b[114514];
int cnt[115414];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
	    cin>>a[i];	
	}
	for(int i=1;i<=n;i++)
	{
		bool w[114514];
		for(int j=1;j<=m;j++)
		{
			w[j]=0;
			b[j]=0;
		}
		for(int j=i;j<=n;j++)
		{
			if(w[a[j]]==0)
			{
				b[j]=a[j];
			    w[a[j]]==1;
			}
			else
			{
				for(int k=1;j<=n;k++)
				{
					if(b[k]==a[j])
					{
						for(int u=k+1;u<=n;u++)
						{
							b[u]==0;
						}
					}
				}
			}
		}
		for(int j=1;j<=n;j++)
		{
			cnt[b[j]]++;
		}
	} 
	sort(a,a+n+1);
	for(int i=1;i<=m;i++)
	{
		cout<<cnt[i]<<" ";
	}
	return 0;
} 

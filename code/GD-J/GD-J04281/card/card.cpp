#include<bits/stdc++.h>
using namespace std;
int n,m,a[500050],b[300050],c[300030],f[300030];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=m;i++)b[i]=0;
		for(int i=1;i<=n;i++)c[i]=0;
		for(int i=k;i<=n;i++)
		{
			if(b[a[i]]==0)
			{
				b[a[i]]=1;
			}
			else 
			{
				for(int j=i-1;j>=k;j--)
				{
					if(c[j]==0)
					{
						c[j]=1;
						b[a[j]]=0;
					}
					if(a[j]==a[i])break;
				}
				b[a[i]]=1;
			}
			
		}
		for(int i=1;i<=m;i++)
		{
			f[i]+=b[i];	
		}
	}
	for(int i=1;i<=m;i++)cout<<f[i]<<" ";
	return 0;
} 

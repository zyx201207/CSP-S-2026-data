#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[600000],s[300010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(s[a[i]]==0) s[a[i]]=a[i];
	}
	
	for(int i=1;i<=n;i++)
	{
		int b[600000];
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=n;k++)
			{
				if(a[j]==b[k])
				{
					for(int l=k;l<=n;l++) b[l]=0;
					b[k]=a[j];
				}
				else b[k]=a[j];
			}
			
		}
		for(int j=1;j<=n;j++)
		{
			
		}
	}
	return 0;
} 

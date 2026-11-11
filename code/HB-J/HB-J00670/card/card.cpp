#include<bits/stdc++.h>
using namespace std;
int n,m,a[10000005],b[10000005],c[10000005];
int main(){
freopen("card.in","r",stdin);
freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=n;j>=i;j--)
		{
		int flag=0;
			for(int x=i;x<=j-1;x++)
			{
				if(a[x]==a[j]) flag=1;
				}
				if(flag==0) 
				{
					c[a[j]]+=1;
	
				}
				else 
				{
					c[a[j]]+=1;
					break;
					
				}
		}
	
	}
	for(int i=1;i<=m;i++) cout<<c[i]<<' ';
	return 0;
}

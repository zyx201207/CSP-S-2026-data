#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500006],c[500006];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		
		for(int j=i;j<=n;j++)
		{
		if(b[a[j]]==0)
		{
			b[a[j]]=j;
			b[a[j]];
		}
		else
		{
			
			for(int q=b[a[j]];q<j;q++)
			{
				b[a[q]]=0;
			}b[a[j]]=j;
		}
			
		}
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]!=0)
			c[a[j]]++,b[a[j]]=0;
		}
	
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
	return 0;
 } 

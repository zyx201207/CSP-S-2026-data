#include<bits/stdc++.h>
using namespace std;
int a[500002],b[300002];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout)	;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	
	for(int k=1;k<=n;k++){
		int c=k;
	for(int i=k;i<=n;i++){
		for(int j=i+1;j<=n;j++)
		{
			if(a[i]==a[j])
			{
				c=j;
				break;
			} 		}
		}
		for(int j=c;j<=n;j++)
		{
			b[a[j]]++;
			
			
		}
	
}
	for(int i=1;i<=m;i++)
	{
	cout<<b[i]<<' ' ;
	}
	return 0;
}

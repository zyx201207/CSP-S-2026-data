#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	int a[200005];
	int an[200005][200005];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		return 0;
	}
	int maxa=0,x=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=i-1;j++)
		    {
		    if(an[i][m]==an[i-1][m])
			{
				x++;
				}	
			
		   for(int j=1;j<=i-1;j++)
		    {
		    an[i][j]=a[i]%2;
			a[i]/2;	
			}
			}
			
			
		
	}
	return 0;
} 

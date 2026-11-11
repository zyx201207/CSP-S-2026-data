//GZ-J00190 南明区山水中学 赵宇涵 

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,a[n+3],b[n+3],maxx=0,mexx=0;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
		
			if(a[j]>maxx||a[j]!=b[i])
			{
				maxx=a[j];
				
			}
			
		}
		b[i]=maxx;
		
	}
	cout<<b[m];
	return 0;
}

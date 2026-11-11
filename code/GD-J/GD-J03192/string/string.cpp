#include <iostream>
using namespace std;
int m,n,p;
char w;
int app[1000000];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>m>>w;
		for(int j=1+p;j<=m+p;j++)
		{
			app[j-1]=w;
		}
		p+=m;
	} 
	int ans=0,l=0,r=m+p-1;
	while(l<r)
	{
		if(app[l]!=app[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;
	return 0;
 } 

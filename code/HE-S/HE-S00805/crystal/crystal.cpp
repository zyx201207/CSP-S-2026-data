#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","r",stdout);
	int n,m,ans=0,b,c=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];

	for(int i=1;i<=n;i++)
	{
		c+=1;
		b==a[n]-a[n-c];
		if(a[n]==a[n-c]+b)
			ans++;
			m-=b;
		if(a[n-c-1]+m<a[n])
		{
			cout<<ans+1;
			return 0;	
		}
		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

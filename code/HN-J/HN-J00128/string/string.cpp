#include <bits/stdc++.h>
using namespace std;
long long a[200010];
char b[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long ans=0;
	long long n;
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
	}
	long long x=1,y=n,s;
	while(x<y)
	{
		s=min(a[x],a[y]);
		a[x]-=s;
		a[y]-=s;
		if(b[x]!=b[y])
		{
			ans+=s;
		}
		if(a[x]==0)
		{
			x++;
		}
		if(a[y]==0)
		{
			y--;
		}
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

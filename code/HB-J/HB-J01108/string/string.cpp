#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n,ans=0;cin>>n;
	vector<char> s;
	int a[n];
	char b[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i]>>b[i];
	}
	int x=0,y=n-1;
	while(1)
	{
		if(b[x]!=b[y])
		ans+=min(a[x],a[y]);
		if(a[x]>a[y])
		{
			a[x]-=a[y];
			y--;
		}
		else if(a[x]==a[y])
		{
			x++;
			y--;
		}
		else
		{
			a[y]-=a[x];
			x++;
		}
		if(x==y)
		{
			cout<<ans;
			return 0;
		}
	}
	
}

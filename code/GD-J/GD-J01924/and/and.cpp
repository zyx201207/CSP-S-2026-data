#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,x,id;
	cin>>n>>m;
	long long ans=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		ans=max(x,ans);
	}
	if(m==1)
	{
		
		sort(a+1,a+n+1,cmp);
		
		
	    cout<<a[1];
	}

	return 0;
}

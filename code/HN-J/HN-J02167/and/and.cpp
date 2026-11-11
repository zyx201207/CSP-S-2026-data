#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,i,m;
	cin>>n>>m;
	for(i=0;i<n;i++)
	  cin>>a[i];
	int ans=0,t,k;
	k=m;
	for(i=0;i<n-m+1;i++)
	{
		for(k=i;k<m+i;k++)
		  t=a[k]&a[k+1];
		if(t>ans)
		  ans=t;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

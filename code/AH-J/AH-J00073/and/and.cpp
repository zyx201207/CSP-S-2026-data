#include <bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,ans;
int a[2*N],b[2*N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%d",a+i);
		ans=max(a[i],ans);
	}
	if(m==1)
	{
		cout<<ans;
		exit(0);
	} 
	else 
	{
		cout<<a[n];
	}
	return 0;
} 

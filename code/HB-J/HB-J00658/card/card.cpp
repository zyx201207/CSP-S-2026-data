#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]!=a[i]) b[i]=i;
	}
	for(int i=1;i<=n;i++) 
	{
		if(b[i]!=0) cout<<b[i]<<" ";
	}
	return 0;
}

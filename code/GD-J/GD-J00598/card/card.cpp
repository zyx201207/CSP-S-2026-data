#include<bits/stdc++.h>
using namespace std;
long long INF=5*1e5+5;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[INF],b[INF];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=1;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<a[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

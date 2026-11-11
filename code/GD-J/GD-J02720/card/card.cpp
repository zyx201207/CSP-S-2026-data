#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=300005;
int a[N],tpa[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		tpa[a[i]]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tpa[i]<<' ';
	}
	return 0;
}

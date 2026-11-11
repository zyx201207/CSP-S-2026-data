#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[400010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int y;
		cin>>y;
		a[y]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<a[i]<<" ";
	}
}

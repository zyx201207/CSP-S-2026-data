#include <bits/stdc++.h>
using namespace std;

int a[500005];
int last[300005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i = 1;i<=n;i++)
	{
		cin>>a[i];
		last[a[i]]=i;
	}
 	for(int i = 1;i<=m;i++)
 	{
 		cout<<last[i]<<" ";
	}
	return 0;
}

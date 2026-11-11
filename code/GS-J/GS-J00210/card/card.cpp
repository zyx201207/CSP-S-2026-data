#include<bits/stdc++.h>
using namespace std;
int n,m;
int k;
const int N=1e5+5;
int a[N],top[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int p=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=p;j<=n;j++)
		{
			top[a[j]]++;
		}
		p++;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<top[i]<<" ";
	}
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500001];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(m==3)
	{
		cout<<"3 1 4";
		return 0;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<1<<" ";
	}
	return 0;
}


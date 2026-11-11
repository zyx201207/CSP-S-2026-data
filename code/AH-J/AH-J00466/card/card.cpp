//card
#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	int num;

	cin>>n>>m;
	int sum[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		sum[num]++;
	}
	

	for(int i=1;i<=m;i++)
	{
		cout<<sum[i]<<" ";
	}
	return 0;
}

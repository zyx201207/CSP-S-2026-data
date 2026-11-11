#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[999999],cnt;
vector<int>g;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		if(a[i+1]!=a[i])
		{
			cnt++;
			cout<<i<<' ';
		}	
	}
	return 0;
}


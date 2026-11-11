#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[500050];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	bool b=1;
	for(int i=1;i<=n;i++)
	{
		if(a[i]!=a[i+1])
		{
			b=0;
			break;
		}
	}
	if(b)
		for(int i=1;i<=n;i++)
			cout<<1<<' ';
	
}

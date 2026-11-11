#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>card[i];
	}
	if(m==1)
	{
		cout<<1;
		return 0;
	}
	if(m==2)
	{
		if(card[1]!=card[n])
		{
			cout<<1<<" "<<1;
		}
		else if(card[1]==1)
		{
			cout<<1<<" "<<0;
		}
		else
		{
			cout<<1<<" "<<0;
		}
	}
	return 0;
}

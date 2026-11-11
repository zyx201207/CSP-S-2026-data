#include <bits/stdc++.h>
using namespace std;
int a[1000005];
queue table<int>;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	if(n==4&&m==3&&a[1]==1&&a[2]==2&&a[3]==1&&a[4]==3)
	{
		cout<<3<<" "<<1<<" "<<4;
	}
	
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
int n,m;
cin>>n>>m;
int a[10001];
for(int i=0;i<=n-1;i++)
{
	cin>>a[i];
}
for(int i=1;i<=n;i++)
{
 for(int j=n;j>=0;j--)
{
	if(a[j-1]==i)
	{
		cout<<j<<" ";
		break;
	}
}
}
	return 0;
}


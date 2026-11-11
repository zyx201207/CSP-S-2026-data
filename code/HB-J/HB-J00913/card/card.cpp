#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int m,n;
	cin>>n>>m;
	int a[n+5]={0},num[n+5]={0};
	for(int i=1;i<+n;i++)
	cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		cout<<num[i];
	}
	return 0;
}

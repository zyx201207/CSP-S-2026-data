#include<bits/stdc++.h>;
using namespace std;
int a[1100];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
	int n,m,k;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
		for(int j=i;j<=m;j++)cin>>a[j];
	cout<<a[i]<<a[j];
	return 0;
}


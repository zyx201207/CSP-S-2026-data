#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,a[100000];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a,a+n+1); 
	cout<<a[n]<<" "<<a[1]<<" "<<a[1]+a[n]; 
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[2000005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m,som=999999;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n+1);
	for(int i=n-m+1;i<n;i++)
	{
		som=min(som,min(a[i],a[i+1]));
	}
	cout <<som;
	return 0;
}

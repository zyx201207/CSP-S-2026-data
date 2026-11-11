#include <bits/stdc++.h>
using namespace std;
int n,m;int a[200005];
int main ()
    {
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (m==1);
		{
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
		}
	
	return 0;
}

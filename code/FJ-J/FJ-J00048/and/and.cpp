#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
int ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i];
	while(n)
	{
		if(n%2==0)ans++;
		n/=2;
	}
	
	cout<<ans;
	
	return 0;
}

//GZ-J00148，任润淏，贵阳市第三实验中学
#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m; 
	long long a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0; 
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(m==n)
	{
		int t=a[1];
		for(int i=2;i<=n;i++)
			t=t&a[i];
		cout<<t;
		return 0;
	} 
	else cout<<a[m];
	return 0;
}

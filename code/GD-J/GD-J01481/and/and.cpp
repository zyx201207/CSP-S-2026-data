#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5+10;
long long n,m,ans;
long long a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--)
	{
		if(m<=0) break;
		ans=ans&a[i];
		m--;
	}
	cout<<ans;
	return 0;
}

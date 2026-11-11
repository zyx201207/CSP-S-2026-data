#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long n,m,a[N];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int curr=m-1;
	int ans=a[n];
	for(int i=n-1;i>=1;i--)
	{
		if(curr==0) break;
		curr--;
		ans&=a[i];
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+7;
long long n,m,a[N],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,greater<long long>());
	for(int i=2;i<=m;i++)
	{
		a[i]=a[i]&a[i-1];
	}
	cout<<a[m];
}

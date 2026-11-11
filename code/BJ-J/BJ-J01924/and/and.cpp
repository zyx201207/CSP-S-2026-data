#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
using namespace std;
const int N=2e5+10;
ll a[N];
int main()
{
	ios::sync_with_stdio(false);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	cout<<a[n-m+1];
	return 0;
}

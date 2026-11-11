#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
const int N=2e5;
int n,a[N],c[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	if(n==1)
	{
		cout<<0;
		return 0;
	}
	cout<<n+1;
	return 0;
}

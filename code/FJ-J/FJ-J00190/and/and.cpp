#include<bits/stdc++.h>
using namespace std;
int n,m,a[200010],maxn,cnt;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		cnt+=i;
	}
	sort(a+1,a+n+1);
	for(int i=m;i>=2;i--)
	{
		maxn=a[n]&a[n-1];
		n--;
	}
	cout<<maxn;
	return 0;
}

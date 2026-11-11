#include<bits/stdc++.h> 
using namespace std;
const int maxn=200005;
long long a[maxn];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	long long mx=-999;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		
	}
	sort(a+1,a+n+1,cmp);
	long long c=a[1];
	for(int i=2;i<=m;i++)
	{
		c&=a[i];
	}
	cout<<c;
	return 0;
}

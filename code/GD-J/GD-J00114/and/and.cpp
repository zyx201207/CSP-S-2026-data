#include<bits/stdc++.h>
using namespace std;
long long ans=0;
long long a[200005];
bool cmp(int x,int y)
{
	return x>y;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i]; 
	}
	sort(a+1,a+n+1,cmp);
	for (int i=1;i<m;i++)
	{
		ans=a[i]&a[i+1];
	}
	cout<<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y)
{
	return x>y;
}
const int N=300000;
int a[N];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	int sum=a[1]&a[1];
	for(int i=2;i<=m;i++)
	{
		sum&=a[i];
	}
	cout<<sum;
	return 0;
}

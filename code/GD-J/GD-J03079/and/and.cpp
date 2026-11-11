#include <bits/stdc++.h>
using namespace std;
int n,m,a[300000],b[300000];
long long ans;
bool cmp(int &a, int &b)
{
	if(a<b)
	{
		return a>b;
	}
}
int main()	
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	for (int i=1;i<=n;i++)
	{
		cin >>a[i];
	}
    sort(a,a+1+n,cmp);
    if(m==1)
    {
    	
		cout << (a[1] & 1);
	}
	else {
	ans =(a[1]&a[2]);
	for (int i=3;i<=m;i++)
	{
		ans = (ans&a[i]);
	}}
	cout <<ans;
	
	
	return 0;
}

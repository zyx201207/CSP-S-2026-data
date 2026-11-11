#include <bits/stdc++.h>
using namespace std;
int a[20010];
int b[20010];
int f(int n,int m)
{
	return n &= m;
}
int main()
{
	freopen("and1.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;//m个数，n总数 
	for (int i=1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i < n;i++)
	{
		b[i]=f(a[i],a[i+1]);
		cout << b[i] <<" ";
	}
	return 0;
 } 

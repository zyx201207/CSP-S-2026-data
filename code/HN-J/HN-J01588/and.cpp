#include<bits/stdc++.h> 
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n, m, a[200000],c[200000];
	cin >> n >> m;
	for(int i = 0; i < n;i++)
	{
		cin >> a[i];
	}
    sort(a+ n,a);
    for(int i = 0; i < m;i++)
	{
		c[i] = a[i];
	}
	sort(c,c+n);
	cout << a[1];
	return 0; ;
}

#include <bits/stdc++.h>
using namespace std;
long long a[1000000];
long long num[1000000];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	sort(a,a+n);
    cout << a[m-1];
}

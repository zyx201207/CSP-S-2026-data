#include<bits/stdc++.h>
using namespace std;
long long a[200010];
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int m,n;
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
    	cin >> a[i];
	 }
	 sort(a,a+n);
    if(m == 1)
    {
    	cout << a[n];
    	return 0;
	 }
	 if(a[n-1] == a[n-2])
     {
         cout << a[n-2];
         return 0;
     }
	 cout << a[n-1];
    return 0;
}


#include <bits/stdc++.h>

using namespace std;
const int N = 2e9+5;
int a[N];
int main()
{
    freopen ("and.in","r",stdin);
	freopen ("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a+1,a+n+1,greater());
    for (int i = 0; i < m;i++)
    {
        a[i] = a[i] | a[i+1];
    }
    cout << a[m];
    return 0;
}



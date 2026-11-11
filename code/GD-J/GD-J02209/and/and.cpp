#include<bits/stdc++.h>
using namespace std;
long long a[200005];
int main()
{
	freopen("r", "and.in", stdin);
	freopen("w", "and.out", stdout);
    int n,m;
    cin >> n >> m;
    int sum;
    cin >> a[1];
    sum=a[1];
    for(int i = 2; i <= n; i++)
    {
        cin >> a[i];
        if(n == m)
           sum &= a[i];
    }
    cout << sum;
    return 0;
}

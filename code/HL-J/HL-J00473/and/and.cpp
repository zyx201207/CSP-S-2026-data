#include<bits/stdc++.h>
using namespace std;
const int N = 200005;
int a[N];
long long b, t;
int main()
{
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 0 ; i < n ; i++)
    {
        cin >> a[i];
        if (a[i - 1] > a[i])
        {
            t = a[i - 1];
            a[i - 1] = a[i];
            a[i] = t;
        }
    }
    cout << t;
    return 0;
}

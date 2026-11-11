#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m, a[200005], maxn=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<=n-m; i++)
    {
        for(int j=i+1; j<n; j++) maxn=max(maxn, a[i]&a[j]);
    }
    cout<<maxn;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
long long n;
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n;
        cout<<n*(n-1)<<'\n';
    }
    return 0;
}

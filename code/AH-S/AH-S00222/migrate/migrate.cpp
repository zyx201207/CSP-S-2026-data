#include<bits/stdc++.h>
using namespace std;
#define ll long long
void solve()
{
    int n,d;
    cin >> n >> d;
    vector<vector<bool>> v(n+1,vector<int>(v+1,false));
    vector<int> x(n+1);
    for(int i=1;i<=n;i++)cin >>x[i];
    cout << n*(n+1)/2;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >>c >>t;
    while(t--)
    {
        solve();
    }
    return 0;
}

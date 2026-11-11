#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    if(n == 0 or m == 0) {cout<<0; return 0;}
    vector<long long> v(n);
    for(long long i = 0;i < n;i++) cin>>v[i];
    sort(v.begin(),v.end(),greater<long long>());
    long long ans = v[0];
    for(long long i = 1;i < m;i++) ans &= v[i];
    cout<<ans;
    return 0;
}

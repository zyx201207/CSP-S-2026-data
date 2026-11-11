#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    vector<long long> k(n);
    k[0] = 0;
    long long a,b;
    cin>>a;
    for(long long i = 1;i < n;i++)
    {
        cin>>b;
        k[i] = b - a;
        a = b;
    }
    long long ans = 1;
    for(int i = 1;i < n;i++)
    {
        if(m >= abs(k[i] * i))
        {
            m -= abs(k[i] * i);
            ans++;
        }
        else break;
    }
    cout<<ans;
    return 0;
}

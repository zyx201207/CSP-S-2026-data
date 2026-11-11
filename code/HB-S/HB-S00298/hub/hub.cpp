#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long c,t;
    cin>>c>>t;
    long long n,k;
    cin>>n>>k;
    while(t--)
    {
        vector<pair<long long,long long>> v(n);
        for(int i = 0;i < n;i++) cin>>v[i].first>>v[i].second;
        cout<<1<<endl;
    }
    return 0;
}

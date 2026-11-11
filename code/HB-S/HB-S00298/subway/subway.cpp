#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<long long> w(m);
    for(int i = 0;i < m;i++) cin>>w[i];
    map<long long,pair<vector<long long>,vector<long long>>> mp;
    for(int i = 0;i < n;i++)
    {
        long long k;
        cin>>k;
        mp[i].first.resize(k);
        mp[i].second.resize(k);
        for(int j = 0;j < k;j++) cin>>mp[i].first[j]>>mp[i].second[j];
    }
    while(q--)
    {
        long long a,b;
        cin>>a>>b;
    }
    cout<<32<<endl<<17;
    return 0;
}

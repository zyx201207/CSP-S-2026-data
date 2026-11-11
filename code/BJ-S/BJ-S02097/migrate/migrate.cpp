#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+100;
#define int long long
int c;
int t;
void solve()
{
    int n,d;
    cin >> n >> d;
    int mp[N];
    vector<pair<int,int> > p;
    for(int i = 1;i <= n;i++)
        cin >> mp[i];
    for(int i = 1;mp[i]+d < mp[n] && i <= n-3;i++)
        if(mp[i+2]-mp[i] <= d && mp[i+3]-mp[i] > d && mp[i+3]-mp[i+1] <= d)
        {
            p.push_back({i,i+3});
        }
    if(p.empty())
    {
        cout << 0 << endl;
        return;
    }
    sort(p.begin(),p.end());
    /*
    int ans = 0;
    for(int i = 0;i < p.size();i++)
    {
        if(i != 0 && i != p.size()-1)
            ans += (p[i-1].second-p[i].first)*(p[i+1].first-p[i].second);
        else if(i != 0)
            ans += (p[i-1].second-p[i].first)*(n-p[i].second);
        else if(i != p.size()-1)
            ans += p[i].first*(p[i+1].first-p[i].second);
        else
            ans += p[i].first*(n-p[i].second);
    }
    */
    cout << p.size() << endl;
    return;
}
signed main()
{
    freopen("migrate.out","w",stdout);
    freopen("migrate.in","r",stdin);
    cin >> c;
    int a;
    cin >> a;
    while(a--)
        solve();
    fclose(stdin);
    fclose(stdout);
    return 0;
}

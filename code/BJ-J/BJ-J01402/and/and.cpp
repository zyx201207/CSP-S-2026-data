#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 2e5+5;
const int M = 35;
int a[N],cnt[M],vis[N];
vector<int> bsx[M];
signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,m; cin>>n>>m;
    for(int i = 1;i<=n;i++) cin>>a[i];
    for(int i = 1;i<=n;i++)
    {
        for(int base = 0;base<=31;base++) if((a[i]>>base)&1) cnt[base]++; else bsx[base].push_back(i);
    }
    int maxans = 0;
    for(int i = 31;i>=0;i--)
    {
        if(cnt[i] >= m)
        {
            maxans += (1<<i);
            for(auto j:bsx[i])
            {
                if(vis[j]) continue;
                vis[j] = 1;
                for(int base = 31;base>=0;base--) if((a[j]>>base)&1) cnt[base]--;
            }
        }
        else continue;
    }
    cout<<maxans<<endl;
    return 0;
}

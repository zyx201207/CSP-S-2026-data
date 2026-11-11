#include <bits/stdc++.h>
#define ll long long
#define fi first
#define sec second
int ans,cnt;

using namespace std;

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int c, n, m, d, q;cin>>c>>n>>m>>d>>q;
    int zt[c];for(int i=0;i<c;i++) cin>>zt[i];
    vector<pair<int,int>> time[n];
    for(int i=0;i<n;i++){
            int cishu;cin>>cishu;
    for(int j=0;j<cishu;j++){
        int zha,lu;cin>>zha>>lu;time[i].push_back({lu,zha});cnt+=lu;
        }
        sort(time[i].begin(),time[i].end());ans=min(ans,cnt);
    }
    cout << ans;

    return 0;
}

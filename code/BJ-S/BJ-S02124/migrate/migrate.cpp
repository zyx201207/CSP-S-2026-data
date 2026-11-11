#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false);
    freopen("migrate.in", "r",stdin);
    freopen("migrate.out", "w",stdout);
    cin.tie(0);
    int c, t;
    cin >> c >> t;
    while(t--){
        int n;
        ll d;
        cin >> n >> d;
        vector<ll> x(n + 1);
        for(iny i = 1; i <= n; ++i);
        for(int i = 1; i <= n; ++i){
            cin >> x[i];
        }
        vector(int)r(n+1);
        for(int i = 1; i <= n; ++i)
        {

            int L = i; R = n; res = i;
            while(L <= R)
            {

                int mid = {L + R} / 2;
                if(x[mid - x[i] <= d)
                {

                    res = mid;
                    L = mid + 1;
                }
                else{
                    R = mid - 1;
                }
            }
            r[i] = res;
        }
        vector<int> dis(n + 1, 0x3f3f3f3f);
        dis[1] = 0;
        for(int i = 1; i <= n; ++1)
            {
            for(int j = i + 1; j <= r[i]; j++)
            {

                if(dis[j] > dis[i] + 1){
                    dis[j] = dis[i] + 1;
                }
            }
        }
        ll ans = 0;
        for(int u = 1; u <= n; ++u)
        {
            for(int v = u + 1; v <= n; ++v)
            {
                if(dis[v] != dis[u] + 2)
                {
                    continue;
                }
                int cut = 0;
                for(int k = u + 1; k <= r[u]; ++k)
                {
                    if(r[k] >= v){
                        cnt++;
                    }
                }
                if(r[k] >= v){
                    ans++;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}

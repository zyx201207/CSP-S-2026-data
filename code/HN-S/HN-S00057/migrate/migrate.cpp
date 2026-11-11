#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int mx = 5.1e5;
long long x[mx];
long long s[mx], f[mx];

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);

    int c, t;
    cin >> c >> t;
    while(t--){
        long long n, d;
        cin >> n >> d;
        for(int i = 1; i <= n; ++i) cin >> x[i];
        long long ans = 0;

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j) s[j] = mx, f[j] = 0;
            s[i] = 0, f[i] = 1;

            deque <int> q;
            q.push_back(i);

            for(int j = i + 1; j <= n; ++j){
                while(!q.empty() && x[j] - x[q.front()] > d) q.pop_front();
                if(q.empty()) break;
                s[j] = s[q.front()] + 1;


                for(int k = q.front(); k < j; ++k){
                    if(s[j] - 1 == s[k])
                    f[j] += f[k];
                }
                if(f[j] == 2) ++ans;

                while(!q.empty() && s[q.back()] > s[j]) q.pop_back();
                q.push_back(j);
            }
        }

        cout << ans << '\n';
    }

}

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1e14
const int N = 2e6 + 5;
int f[N],dp[N],a[N],n,d,c,t;
deque<int> q,S;
void mig(int c){

    cin >> n >> d;

    for (int i = 1;i <= n + 3;i++){
        f[i] = INF;
        dp[i] = 0;
    }

    int cnt = 0,cur = 0;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for (int i = 1;i <= n;i++){
        for (int j = 1;j <= n + 3;j++){
            f[j] = INF;
            dp[j] = 0;
        }
        dp[i] = 1;
        f[i] = 0;
        while (!q.empty()) q.pop_back();
        q.push_back(i);
        for (int j = i + 1;j <= n;j++){
            while (!q.empty() && abs(a[q.front()] - a[j]) > d) q.pop_front();
            while (!q.empty() && f[q.front()] + 1 < f[q.back()]) q.pop_back();
            if (q.empty()){
                q.push_back(j);
                continue;
            }
           int x = q.front();
          // cout << f[x] << "?" << f[2] << endl;
           // S.push_back(x);
          //  q.pop_back();
            while (!q.empty() && f[q.front()] == f[x] && dp[j] <= 3){
                    //cout << "case1" << q.front() << q.size() << " ";
                dp[j] += dp[q.front()];
                S.push_back(q.front());
                q.pop_front();
           //cout << j << " " << dp[j];
            }
            while (!S.empty()) {
                q.push_front(S.back());
                S.pop_back();
            }
            if (dp[j] == 2) cnt++;
            f[j] = f[q.front()] + 1 ;
            q.push_back(j);
          //  cout << j <<":" << f[j] << endl;
        }
    }
    cout << cnt <<endl;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    for (int i = 1;i <= t;i++){
        mig(c);
    }
    return 0;
}

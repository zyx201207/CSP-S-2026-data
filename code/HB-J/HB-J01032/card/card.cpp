#include <bits/stdc++.h>
using namespace std;

int card[500005], have[300005], ans[300005];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    int n, m;
    cin >> n >> m;

    bool AAA = 1;

    card[0] = 0;
    for(int i = 1; i <= n; i++){
        cin >> card[i];
        if(card[i] <= card[i-1])AAA = 0;
    }

    if(AAA == 1){
        for(int i = 0; i < m; i++)
            cout << 0 << ' ';
        return 0;
    }

    memset(ans, 0, sizeof(ans));

    stack <int> s;

    for(int i = 1; i <= n; i++){
        memset(have, 0, sizeof(have));
        for(int j = i; j <= n; j++){
            int ka = card[j];
            if(!s.empty() && have[ka]){
                while(!s.empty() && s.top() != ka){
                    int t = s.top();
                    have[t] = 0;
                    s.pop();
                }
                if(!s.empty()){
                    int t = s.top();
                    have[t] = 0;
                    s.pop();
                }
            }

            s.push(ka);
            have[ka] = j;
        }
        while(!s.empty()){
            ans[s.top()]++;
            s.pop();
        }
    }

    for(int i = 1; i <= m; i++)cout << ans[i] << ' ';


    return 0;
}

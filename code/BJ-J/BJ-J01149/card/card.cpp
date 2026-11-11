#include<bits/stdc++.h>
using namespace std;
//#define int long long
const int Maxn = 5e5 + 5, Maxm = 3e5 + 5;
int a[Maxn], ans[Maxm];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    if(n<=505){
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int t = 1; t <= n; t++){
            deque<int> dq;
            for(int i = t; i <= n; i++){
                for(int x = 0; x < dq.size(); x++){
                    if(dq[x]==a[i]){
                        while(dq.size()>x){
                            dq.pop_back();
                        }
                    }
                }
                dq.push_back(a[i]);
            }
            for(int i = 0; i < dq.size(); i++){
                ans[dq[i]]++;
            }
        }
        for(int i = 1; i <= m; i++){
            cout << ans[i] << " ";
        }
    }else{
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            ans[a[i]] = i;
        }
        for(int i = 1; i <= m; i++){
            cout << ans[i] << " ";
        }

    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
int n;
long long m, ans = 0, mn = 0;
long long val[maxn];
long long w[maxn];
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++) cin>>val[i];
    sort(val + 1, val + n + 1);
    int midnum = val[(int)((n + 1) / 2)];
    int mididx = (int)((n + 1) / 2);
    while(val[mididx + 1] == midnum) mididx++;
    for(int i = 1; i <= mididx; i++){
        w[i] = val[i] - midnum;
    }
    for(int i = mididx; i >= 1; i--){
        if(w[i] <= m){
            ans++;
            m -= w[i];
        }
    }
    mn = ans;
    for(int i = mididx + 1; i <= n; i++){
        if((val[i] - val[mididx]) * mn <= m){
            ans++;
            m -= (val[i] - val[mididx]) * mn;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
struct st{
    long long loa;
    long long fro;
};

inline void solve(){
    long long x[5009];
    bool mark[5009][5009];
    for(long long i = 0;i <= 5000;i++){
        for(long long j = 0;j <= 5000;j++){
            mark[i][j] = 0;
        }
    }
    long long n,d;
    long long ans = 0;
    cin >> n >> d;
    for(long long i = 1;i <= n;i++){
        cin >> x[i];   
    }
    for(long long i = 1;i <= n - 1;i++){
        long long pos = i + 1;
        while(x[pos] - x[i] <= d){
            pos ++;
            mark[pos][i] = 1;
        }
    }
    for(long long i = n;i > 1;i--){
        long long pos = i - 1;
        while(x[i] - x[pos] <= d){
            pos --;
            mark[pos][i] = 1;
        }
    }
    for(long long i = 1;i <= n;i++){
        for(long long j = i + 1;j <= n;j++){
            long long len = 1;
            long long las = i,pos = i;
            bool mk[5009];
            vector<st> vis;
            long long from[5009];
            for(long long k = 1;k <= n;k++){
                from[k] = -1;
            }
            for(long long k = 1;k <= n;k++){
                mk[i] = 0;
            }
            //mk[1] = 1;
            vis.push_back({i,i});
            long long num = 1;
            for(long long k = i;k <= j;k++){
                if(x[k] - x[las] <= d){
                    pos = k;
                } else {
                    if(x[k] - x[k - 1] > d){
                        goto lll;
                    }
                    len ++ ;
                    vis.push_back({k - 1,las});
                    from[k - 1] = las;
                    las = k - 1;
                    //mk[k - 1] = 1;
                    pos = k;
                }
                if(k == j){
                    vis.push_back({j,las});
                }
            }
            //cerr << i << ' ' << j << ' ' << len << endl;
            /*for(auto aaa:vis){
                cerr << aaa.fro << ' ' << aaa.loa << endl;
            }*/
            for(long long k = 0;k < vis.size();k++){
                if(vis[k].loa == i){
                    continue;
                } else if(vis[k].loa == j){
                    continue;
                }
                long long times = 1;
                long long pos = vis[k].loa - 1;
                while(x[vis[k + 1].loa] - x[pos] <= d){
                    times ++;
                    if(times > 2){
                        goto lll;
                    }
                    pos--;
                }
                num *= times;
                if(num > 2){
                    goto lll;
                }
            }
            if(num == 2){
                ans ++;
                //cerr << len << ' ' << i<< ' ' << j << "\n--------------------------"<< endl;
            }
            lll:;
            //cerr << i<< ' ' << j << "\n--------------------------"<< endl;
        }
    }
    cout << ans << endl;
    return;

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;

    while(t--){
        solve();
    }
    return 0;
}
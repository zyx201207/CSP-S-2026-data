#include <bits/stdc++.h>
using namespace std;
#define fir first
#define sec second
template <class TT>
using vc=vector<TT>;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    long long test_case, T;
    cin >> test_case >> T;
    while(T--){
        long long n, d;
        cin >> n >> d;
        vc<long long> x(n+1), pre(n+1), nxt(n+1);
        for(long long i=1;i <= n;i++){
            cin >> x[i];
        }
        pre[1]=1;
        for(long long i=2;i <= n;i++){
            pre[i]=pre[i-1];
            while(abs(x[pre[i]]-x[i]) > d) pre[i]++;
        }
        nxt[n]=n;
        for(long long i=n-1;i >= 1;i--){
            nxt[i]=nxt[i+1];
            while(abs(x[nxt[i]]-x[i]) > d) nxt[i]--;
        }
        if(test_case == 11 || test_case == 12){
            vc<long long> ans(n+1);
            vc<long long> dis(n+1, -1), cnt(n+1);
            dis[1]=0; cnt[1]=1;
            for(long long j=2;j <= n;j++){
                long long st=max(1ll, pre[j]);
                for(long long k=st;k < j && k <= st+3;k++){
                    if(abs(x[j]-x[k]) <= d){
                        if(dis[j] == -1 || dis[k]+1 < dis[j]){
                            dis[j]=dis[k]+1;
                            cnt[j]=cnt[k];
                        }
                        else if(dis[k]+1 == dis[j]) cnt[j]+=cnt[k];
                    }
                }
                if(cnt[j] > 3) cnt[j]=3;
            }
            for(long long i=1;i <= n;i++){
                ans[i]=ans[i-1]+(cnt[i] == 2);
            }
            long long o=0;
            for(long long i=1;i <= n;i++){
                o+=ans[i]+ans[n-i+1];
            }
            cout << o/2 << "\n";
            continue;
        }
        else if(test_case == 12 || test_case == 13){

        }
        // for(long long i=1;i <= n;i++){
        //     cerr << pre[i] << " ";
        // }
        // cerr << "\n";
        // for(long long i=1;i <= n;i++){
        //     cerr << nxt[i] << " ";
        // }
        // cerr << "\n";
        long long ans=0;
        for(long long i=1;i <= n;i++){
            vc<long long> dis(n+1, -1), cnt(n+1);
            dis[i]=0; cnt[i]=1;
            for(long long j=i-1;j >= 1;j--){
                long long st=min(i, nxt[j]);
                for(long long k=st;k > j && k >= st-3;k--){
                    if(abs(x[j]-x[k]) <= d){
                        if(dis[j] == -1 || dis[k]+1 < dis[j]){
                            dis[j]=dis[k]+1;
                            cnt[j]=cnt[k];
                        }
                        else if(dis[k]+1 == dis[j]) cnt[j]+=cnt[k];
                    }
                }
                if(cnt[j] > 3) cnt[j]=3;
            }
            for(long long j=i+1;j <= n;j++){
                long long st=max(i, pre[j]);
                for(long long k=st;k < j && k <= st+3;k++){
                    if(abs(x[j]-x[k]) <= d){
                        if(dis[j] == -1 || dis[k]+1 < dis[j]){
                            dis[j]=dis[k]+1;
                            cnt[j]=cnt[k];
                        }
                        else if(dis[k]+1 == dis[j]) cnt[j]+=cnt[k];
                    }
                }
                if(cnt[j] > 3) cnt[j]=3;
            }
            for(long long i=1;i <= n;i++){
                // cerr << "{" << dis[i] << ", " << cnt[i] << "} ";
                if(cnt[i] == 2) ans++;
            }
            // cerr << "\n";
        }
        cout << ans/2 << "\n";
    }
}
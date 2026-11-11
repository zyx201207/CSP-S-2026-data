#include<bits/stdc++.h>
#define fi first
#define se second
#define int long long
// #define W(x) cerr<<#x<<':'<<x<<'\n'
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
using ll=long long;
using db=long double;
using ull=unsigned long long;
const int N = 2e6+10;// fanweihaimeigai!!!!!!!!!!!!!!!!!!!!!!!!
const int M = 1e5+10;
const int MOD = 1e9+7;
namespace IO{
    template<typename T> inline void rd(T &x){
        x=0;
        bool f = 0;
        char c = gc();
        for(;!isdigit(c);c=gc())if(c=='-')f=1;
        for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
        if(f)x=-x;
    }
    template<typename T> inline void wt(const T &x){
        if(x<0){
            pc('-');
            wt(-x);
            return;
        }
        if(x>9){
            wt(x/10);
        }
        pc(x%10+'0');
    }
}using namespace IO;
int subtask,T,n,d,a[N],dp[N],cnt[N],hd,tl,q[N];

void solve1(){
    while(T--){
        // cin >> n >> d;
        rd(n),rd(d);
        for(int i = 1;i<=n;i++){
            // cin >> a[i];
            rd(a[i]);
        }
        int Ans = 0;
        for(int u = 1;u<=n;u++){
            dp[u] = 0;
            cnt[u] = 1;
            hd = 1,tl = 1;
            q[1] = u;
            for(int i = u+1;i<=n;i++){
                dp[i] = INT_MAX;
                cnt[i] = 0;
                while(hd<=tl&&a[i]-a[q[hd]]>d)++hd;
                if(hd<=tl){
                    dp[i] = dp[q[hd]]+1;
                    for(int j = hd;j<=tl;j++){
                        if(dp[q[j]]==dp[q[hd]]){
                            cnt[i] += cnt[q[j]];
                        }
                        if(cnt[i]>2)break;
                    }
                    while(hd<=tl&&dp[q[tl]]>dp[i])--tl;
                    q[++tl] = i;
                }
                if(cnt[i]==2){
                    Ans++;
                }
            }
        }
        // cout << Ans << '\n';
        wt(Ans);
        pc('\n');
    }
}
void solve2(){
    while(T--){
        // cin >> n >> d;
        rd(n),rd(d);
        for(int i = 1;i<=n;i++){
            // cin >> a[i];
            rd(a[i]);
        }
        int diff = a[2] - a[1];
        if(diff>=d){
            // cout << "0\n";
            wt(0);
            pc('\n');
            continue;
        }
        int k = d/diff;
        int Ans = n-2*k+1;
        Ans = max(Ans,0ll);
        // cout << Ans << '\n';
        wt(Ans);
        pc('\n');
    }
}
void solve3(){
    while(T--){
        // cin >> n >> d;
        rd(n),rd(d);
        for(int i = 1;i<=n;i++){
            // cin >> a[i];
            rd(a[i]);
        }
        wt(0);
        pc('\n');
    }
}
signed main(){
    // cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    // cin >> subtask >> T;
    rd(subtask),rd(T);
    if(subtask==11||subtask==12){
        solve2();
    }else if(subtask==13||subtask==14){
        solve3();
    }else{
        solve1();
    }
    return 0;
}
/*
compile:
g++ -o C C.cpp -O2 -static -std=c++14

10 22
0 7 14 21 28 35 42 49 56 63

5

*/
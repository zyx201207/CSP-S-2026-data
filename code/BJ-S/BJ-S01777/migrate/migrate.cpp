#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll D,a[2000005],ansn,ans[2000005][2];
int c,T,n,L[2000005],R[2000005],d[2000005];
vector<int> v[2000005];
inline void dfs(int x,int y){
    for(int i:v[x]){
        if(L[x] <= i) d[i]++,d[y]--;
        else d[i]++,d[x]--;
        if(L[x] != i) dfs(i,x);
        else dfs(i,y);
    }
}
inline void pushup(int x){
    for(int i:v[x]){
        pushup(i);
        if(x - 1 != i){
            if(L[x - 1] < i) ans[x - 1][0]++;
            if(L[x - 1] == i) ans[x - 1][0] += d[i];
            else if(L[x - 1] == i - 1 && L[x] == i) ans[x - 1][0] += ans[i - 1][0];
        }
        //cerr << x << '@' <<ans[x - 1][0] << ' ';
        if(L[x] == i - 1) ans[x][1] += ans[i - 1][0];
        else if(L[x] == i) ans[x][1] += ans[i][1];
        d[x] += d[i];
    }
    //cerr << x << '?' << d[x] << '?' << ans[x][0] << '?' << ans[x][1] << ' ';
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> c >> T;
    while(T--){
        ansn = 0;
        cin >> n >> D;
        for(int i = 1;i <= n;i++) cin >> a[i];
        int now = 1;
        for(int i = 1;i <= n;i++){
            while(now < n && a[now + 1] - a[i] <= D) now++;
            R[i] = now;
        }
        now = n;
        for(int i = n;i > 0;i--){
            while(now > 1 && a[i] - a[now - 1] <= D) now--;
            L[i] = now;
        }
        //cerr << n << '\n';
        for(int i = 1;i <= n;i++){
            if(R[i] > i) v[R[i]].push_back(i);//,cerr <<R[i] << '-' <<i << ' ';
            else v[0].push_back(i);//,cerr <<0 <<'-' <<i << ' ';
        }
        dfs(0,0);
        pushup(0);
        //for(int i = 1;i <= n;i++) cerr << i <<'?' << ans[i][0] << '?' <<ans[i][1] << ' ';
        for(int i = 1;i <= n;i++) ansn += ans[L[i]][0] + ans[L[i]][1];//,cerr <<ansn << '!';
        cout << ansn << '\n';
        for(int i = 0;i <= n;i++){
            while(v[i].size()) v[i].pop_back();
            ans[i][0] = ans[i][1] = d[i] = 0;
        }
    }
    return 0;
}

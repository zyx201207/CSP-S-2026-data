#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = 5e+5 + 5, maxp = 505;

int w[maxn];
ll f[maxp][maxp];
vector<pair<int, int> > sid[maxn];

inline ll read() {
    ll ref = 0; bool f = 1; char ch = getchar();
    while(!isdigit(ch)){if(ch == '-') f = 0; ch = getchar();}
    while(isdigit(ch)) ref = (ref << 1) + (ref << 3) + (ch ^ 48), ch = getchar();
    return f ? ref : -ref;
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c = read(), n = read(), m = read(), d = read(), q = read();
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) f[i][j] = 1e+18;
    for(int i = 1; i <= n; i++) f[i][i] = 0;
    for(int i = 1; i <= m; i++) w[i] = read();
    for(int i = 1; i <= n; i++) {
        int T = read();
        while(T--) {
            int a = read(), t = read();
            for(pair<int, int> kp : sid[a]) if(f[kp.first][i] > kp.second + t) f[kp.first][i] = f[i][kp.first] = kp.second + t;
            sid[a].push_back(make_pair(i, t));
        }
    }
    for(int k = 1; k <= n; k++)
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= n; j++) f[i][j] = min(f[i][j], f[k][i] + f[k][j]);
    //for(int i = 1; i <= n; i++) {
    //    for(int j = 1; j <= n; j++) cout << f[i][j] << ' ';
    //cout << endl;
    //}
    //for(int i = 1; i <= m; i++) {
    //        cout << i <<" : ";
    //    for(auto kp :sid[i]) cout << kp.first<< ' ';
    //    cout << endl;
    //}
    while(q--) {
        int l = read(), r = read(); ll answer = 1e+18;
        for(pair<int, int> i : sid[l]) for(pair<int, int> j : sid[r]) answer = min(answer, f[i.first][j.first] + i.second + j.second);
        printf("%lld\n", answer + w[l] + w[r]);
    }

    return 0;
}


//1. 龙long
//2. 数组空间
//3. 手搓阳历

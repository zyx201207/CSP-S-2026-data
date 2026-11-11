#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
constexpr int N = 2e5+10;
int n, m, ar[N];
int bit[N][40], len[N];
void solve(int x, int val){
    int cnt = 0;
    while(val){
        bit[x][++cnt] = val%2;
        val /= 2;
    }
    //reverse(bit[x]+1, bit[x]+cnt+1);
    len[x] = cnt;
}
bool cmp(int a, int b){return a>b;}
long long tpow[40];
int cnt[40];
vector<int> cuse, h[40], use;

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    scanf("%d%d", &n, &m);
    tpow[0] = 1;
    for(int i = 1; i <= 32; ++i) tpow[i] = tpow[i-1]*2;
    for(int i = 1; i <= n; ++i) scanf("%d", ar+i);
    sort(ar+1, ar+n+1, cmp);
    for(int i = 1; i <= n; ++i) solve(i, ar[i]);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= len[i]; ++j){
            cnt[j] += bit[i][j];
            if(bit[i][j]) h[j].push_back(ar[i]);
        }
    for(int i = len[1]; i >= 1; --i)
        if(cnt[i] >= m){
            cuse.push_back(i);
            //cout << cnt[i] << ' ' << i << '\n';
        }
    for(int i = 1; i <= 32; ++i)
        if(h[i].size()) sort(h[i].begin(), h[i].end(), cmp);
    //sort(cuse.begin(), cuse.end(), cmp);
    int ans = 0;
    //cout << cuse[0] << '\n';
    for(int i = 0; i < m; ++i){
        if(ans == 0) ans = h[cuse[0]][i];
        else ans &= h[cuse[0]][i];
        //cout << h[cuse[0]][i] << ' ';
    }
    printf("%d", ans);
    return 0;
}

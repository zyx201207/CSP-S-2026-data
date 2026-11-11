#include<bits/stdc++.h>
#define MAXN 500200
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int n , m , d , ans = 0;
int w[MAXN] = {0} ;
vector<sta> a[MAXN];

void solve(int f , int t){
    int ans = w[f] + w[t];

    cout << ans<< "\n";
}
int main(){
    freopen("subway.in" , "r" , stdin);
    freopen("subway.ans" , "w" , stdout);
    ios :: sync_with_stdio(0);
    cin .tie(0);
    int c , q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin  >> w[i];
    for(int i = 1;i <= n;i++){
        int s; cin >> s;
        for(int j = 1;j <= s;j++) {int x , y; cin >> x >> y; a[m + i].push_back(x); a[x].push_back(m + i); }
    }
    for(int i = 1;i <= q;i++){
        int from , to;
        cin >> from >> to;
        solve(from , to);
    }
    return 0;
}


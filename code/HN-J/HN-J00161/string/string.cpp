#include<bits/stdc++.h>
#define AC return 0;
#define ll long long
#define lll __int128
#define ve vector<int>
#define vel vector<ll>
#define veve vector<ve>
#define veb vector<bool>
#define pb push_back
#define pob pop_back

using namespace std;

const int inf = 1e9;
const int N = 2e5 + 5;
int n, a[N];
char c[N];

/**

bool check(){
    int maxx = 0;
    for(int i = 1; i <= n; i ++){
        maxx = max(maxx, a[i]);
    }
    return maxx <= 500;
}

void S1(){
    string t = " ";
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= a[i]; j ++){
            t += c[i];
        }
    }
    ll ans = 0;
    for(int i = 1, j = t.size() - 1; i <= j; i ++, j --){
        if(t[i] != t[j]){
            ans ++;
        }
    }
    cout << ans;
}

*/

void S2(){
    ll ans = 0;
    for(int i = 1, j = n; i < j; ){
        int k = min(a[i], a[j]);
        a[i] -= k;
        a[j] -= k;
        if(c[i] != c[j]){
            ans += k;
            ///cout << i << ' ' << j << '\n';
        }
        if(a[i] == 0){
            i ++;
        }
        if(a[j] == 0){
            j --;
        }
    }
    cout << ans;
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i ++){
        cin >> a[i] >> c[i];
    }
    S2();
    AC;
}

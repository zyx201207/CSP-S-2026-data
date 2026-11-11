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
const int N = 5e5 + 5;
int n, m, a[N];

void S1(){
    ve ans(m + 1, 0);
    for(int i = 1; i <= n; i ++){
        ve f(m + 1, 0);
        for(int j = i; j <= n; j ++){
            if(f[a[j]]){
                for(int k = f[a[j]]; k < j; k ++){
                    f[a[k]] = 0;
                }
            }
            f[a[j]] = j;
        }
        for(int j = 1; j <= m; j ++){
            ans[j] += (bool)f[j];
        }
    }
    for(int i = 1; i <= m; i ++){
        cout << ans[i] << ' ';
    }
}

bool check1(){
    for(int i = 1; i < n; i ++)
        if(a[i] > a[i + 1])
            return false;
    return true;
}

void Ta(){
    ve ans(m + 1);
    for(int i = 1; i <= n; i ++){
        for( ; i <= n && a[i + 1] == a[i]; i ++);
        ans[a[i]] = i;
    }
    for(int i = 1; i <= m; i ++){
        cout << ans[i] << ' ';
    }
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i =  1; i <= n; i ++)
        cin >> a[i];
    if(check1())
        Ta();
    else
        S1();
    AC;
}

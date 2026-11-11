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
int n, m, ans, a[N];

void dfs(int last, int cnt, int res){
    if(cnt == m){
        ans = max(ans, res);
        return ;
    }
    for(int i = last + 1; i <= n; i ++){
        dfs(i, cnt + 1, (res == -1 ? a[i] : (res & a[i])));
    }
}

void S1(){
    dfs(0, 0, -1);
    cout << ans;
}

void T_a_b(){
    sort(a + 1, a + 1 + n);
    cout << a[n - m + 1];
}

int check(){
    int maxx = 0;
    for(int i = 1; i <= n; i ++)
        maxx =  max(maxx, a[i]);
    return maxx;
}

void S2(){
    sort(a + 1, a + 1 + n);
    cout << a[n - m + 1];
}

int main(){
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i ++)
        cin >> a[i];
    if(n <= 20){
        S1();
    }else if(n <= 2000){
        sort(a + 1, a + n);
        if(m == 1){
            cout << a[n];
        }else if(m == 2){
            int ans = 0;
            for(int i = 1; i <= n; i ++)
                for(int j = i + 1; j <= n; j ++)
                    ans = max(ans, (a[i] & a[j]));
            cout << ans;
        }else{
            int ans = a[1];
            for(int i = 2; i <= n; i ++){
                ans &= a[i];
            }
            cout << ans;
        }
    }else{
        if(check() <= 4){
            S2();
        }else{
            T_a_b();
        }
    }
    AC;
}


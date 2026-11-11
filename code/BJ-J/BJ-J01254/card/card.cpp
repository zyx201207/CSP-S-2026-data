#include <bits/stdc++.h>

using namespace std;

#define ll long long

ll m, n, a[500005], f[500005][3], nxt[500005], ans[500005], sum;

map <ll, ll> mp;

vector <int> vec[300005];

int main(){
    freopen("card.in" , "r", stdin );
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        vec[a[i]].push_back(i);
    }


    for(int i = 1; i <= 300000; i++){
        if(vec[i].size()){
            for(int j = 0; j < vec[i].size(); j++){
                nxt[vec[i][j]] = vec[i][j+1];
            }
            nxt[vec[i][vec[i].size()-1]] = -1;
        }
    }
    int lst = 0;
    for(int i = 1; i <= n; i++){
        if(nxt[i] == -1){
            f[i][2] = vec[a[i]].size()+f[i-1][2];
            ans[a[i]]+=f[i][2];
            lst = i;
        }
    }
    for(int i = 1; i <= m; i++){
        if(i == a[n]) cout << n;
        else cout << ans[i] << " ";
    }
    return 0;
}


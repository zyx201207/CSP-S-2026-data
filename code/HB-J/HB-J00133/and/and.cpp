#include<bits/stdc++.h>
using namespace std;

struct and1{
    int v,use;
}a[200010];

int n, m;
int maxn = 0;
void dfs(int m1, int t, int i){
    if(m1 == 0){
        maxn = max(maxn, t);
        return;
    }
    if(i == 1){
        for(int k = 1; k <= n - m + 1; k++){
            if(a[k].use == 0){
                t = a[k].v;
                a[k].use = 1;
                dfs(m1-1,t,k+1);
                a[k].use = 0;
            }
        }
    }
    else{
        for(int j = i; j <= n - m1 + 1; j++){
            if(a[j].use == 0){
                t = t & a[j].v;
                a[j].use = 1;
                dfs(m1-1,t,j+1);
                a[j].use = 0;
            }
        }
    }
}

int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i].v;
        a[i].use = 0;
    }
    if(m == 1){
        int ans = a[1].v;
        for(int i = 2; i <= n; i++){
            if(a[i].v > ans){
                ans = a[i].v;
            }
        }
        cout << ans;
        return 0;
    }
    if(m == 2){
        int ans = 0, t;
        for(int i = 1; i <= n; i++){
            t = a[i].v;
            for(int j = i+1; j <= n; j++){
                int t1 = t & a[j].v;
                ans = max(ans, t1);
            }
        }
        cout << ans;
        return 0;
    }
    dfs(m,0,1);
    cout << maxn;
    return 0;
}

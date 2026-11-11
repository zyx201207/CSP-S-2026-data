#include<bits/stdc++.h>
using namespace std;
int n;
struct note{
    int a;
    char c;
};
note b[200005];
long long ans;

void dfs(int i, int j){
    if(i >= j) return;
    if(b[i].a == b[j].a){
        if(b[i].c != b[j].c) ans += b[i].a;
        dfs(i + 1, j - 1);
    }
    else{
        if(b[i].a > b[j].a){
            if(b[i].c != b[j].c) ans += b[j].a;
            b[i].a -= b[j].a;
            dfs(i, j - 1);
        }
        else{
            if(b[i].c != b[j].c) ans += b[i].a;
            b[j].a -= b[i].a;
            dfs(i + 1, j);
        }
    }
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for(int i = 1; i <= n; i ++) cin >> b[i].a >> b[i].c;
    dfs(1, n);
    cout << ans;
    return 0;
}

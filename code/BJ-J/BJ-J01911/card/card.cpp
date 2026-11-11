#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int a[N], h[N], s[N];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    stack <int> stk;
    for(int i = 1; i<=n; i++){
        cin >> a[i];
    }
    for(int i = 1; i<=n; i++){
        int p = 1;
        for(int j = i; j<=n; j++){
            if(h[a[j]]){
                while(!stk.empty()&&stk.top()!=a[j]){
                    h[stk.top()] = 0;
                    stk.pop();
                }
                h[a[j]] = 1;
            }else{
                stk.push(a[j]);
                h[a[j]] = 1;
            }
        }
        while(!stk.empty()){
            s[stk.top()]++;
            stk.pop();
        }
        memset(h, 0, sizeof(h));
    }
    for(int i = 1; i<=m; i++){
        cout << s[i] << ' ';
    }
    return 0;
}

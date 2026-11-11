#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 9;

int n, m, a[N], sum[N];

void solve(int s){
    stack<int> stk;
    for(int i = s; i <= n; i++){
        stack<int> t;
        int www = 0;
        while(!stk.empty()){
            t.push(stk.top());
            stk.pop();
            if(t.top() == a[i]){
                www = 1;
                break;
            }
        }
        if(!www){
            while(!t.empty()){
                stk.push(t.top());
                t.pop();
            }
        }
        stk.push(a[i]);
    }
    while(!stk.empty()){
        sum[stk.top()]++;
        stk.pop();
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        solve(i);
    }
    for(int i = 1; i <= m; i++){
        cout << sum[i] << " ";
    }
}

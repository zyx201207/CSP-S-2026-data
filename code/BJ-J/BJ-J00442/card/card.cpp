#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10, M = 3e5 + 10;
stack<int> s;
int n, m, a[N + 5], cnt[M + 5];
bool flag[M + 5];
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int j = 1; j <= n; j++){
        memset(flag, false, m);
        for(int i = j; i <= n; i++){
            if(flag[a[i]]){
                while(s.top() != a[i]){
                    flag[s.top()] = false;
                    s.pop();
                }
            }
            else{
                flag[a[i]] = true;
                s.push(a[i]);
            }
        }
        while(!s.empty()){
            cnt[s.top()]++;
            s.pop();
        }
    }
    for(int i = 1; i <= m; i++) cout << cnt[i] << ' ';
    return 0;
}

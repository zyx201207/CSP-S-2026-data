#include<bits/stdc++.h>
using namespace std;
int a[500010];
int ton[200010];
int ans[300010];
int n,m;
stack<int>stk;
int main(){
   freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    if(n > 5000){
        if(m <= 2){
            if(m == 1){
                cout << n;
                return 0;
            }
            if(a[n] == 1){
                cout << n << ' ';
                int cnt = 0;
                for(int i = 1;i <= n; i++){
                    if(a[i] == 2){
                        cnt++;
                    }
                }
                cout <<cnt;
            }else{
                int cnt = 0;
                for(int i = 1;i <= n; i++){
                    if(a[i] == 1){
                        cnt++;
                    }
                }
                cout << cnt << ' ' << n;
            }
            return 0;
        }
        for(int i = 1;i <= n; i++){
            ans[a[i]] = i;
        }
        for(int i = 1;i <= m; i++){
            cout <<ans[i] << ' ';
        }
        return 0;
    }
    for(int i = 1;i <= n; i++){
        for(int j = i;j <= n; j++){
            if(ton[a[j]]){
                while(stk.top()!= a[j]){
                    ton[stk.top()] = 0;
                    stk.pop();
                }
            }else{
                stk.push(a[j]);
                ton[a[j]] = 1;
            }
        }
        while(!stk.empty()){
            ans[stk.top()]++;
            stk.pop();
        }
        for(int j = i;j <= n; j++){
            ton[a[j]] = 0;
        }
    }
    for(int i = 1;i <= m; i++){
        cout << ans[i] << ' ';
    }
    return 0;
}

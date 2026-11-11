#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for(int i = 1;i <= n;i ++){
        cin >> a[i];
    }
    vector<int> t(m + 1);
    for(int i = 1;i <= n;i ++){
        stack<int> stk;
        vector<int> cnt(m + 1);
        for(int j = i;j <= n;j ++){
            stk.push(a[j]);
            cnt[a[j]] ++;
            for(int k = 1;k <= m;k ++){
                if(cnt[k] > 1){
                    int u = stk.top();
                    stk.pop();
                    cnt[k] --;
                    while(stk.top() == u){
                        cnt[stk.top()] --;
                        stk.pop();
                        if(stk.size() == 0) break;
                    }
                }
            }
        }
        for(int i = 1;i <= m;i ++){
            t[i] += cnt[i];
        }
    }
    for(int i = 1;i <= m;i ++){
        cout << t[i] << " ";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

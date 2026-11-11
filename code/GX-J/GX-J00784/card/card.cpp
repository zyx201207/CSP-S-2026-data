#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m,a[500005],ans[500005] = {};
    bool already[500005] = {};
    stack<int> st;
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(already[a[j]] == 0){
                st.push(a[j]);
                already[a[j]] = 1;
            }
            else{
                while(!st.empty() && st.top() != a[j]){
                    already[st.top()] = 0;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            already[st.top()] = 0;
            st.pop();
        }
    }
    for(int i = 1;i <= m;i++){
        if(ans[i] == 0) continue;
        cout << ans[i] << " ";
    }
    return 0;
}

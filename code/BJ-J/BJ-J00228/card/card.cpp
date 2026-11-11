#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 20;
int n, m, a[maxn], ans[maxn];
bool in_st[maxn];
stack<int> st;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            if(!in_st[a[j]]){
                in_st[a[j]] = true;
                st.push(a[j]);
            }
            else{
                while(st.top() != a[j]){
                    in_st[st.top()] = false;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            ans[st.top()]++;
            in_st[st.top()] = false;
            st.pop();
        }
    }
    for(int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}

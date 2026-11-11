#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 5e5 + 5;
const int M = 3e5 + 5;
int n, m, p = 1, a[N], in[M], ans[M];
stack<int> st;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        if(i > 1 && a[i] < a[i - 1]) p = 0;
    }
    if(p){
        a[n + 1] = m + 1;
        for(int i = 1;i <= n + 1;i++){
            if(a[i] != a[i - 1]) ans[a[i - 1]] += i - 1;
        }
        for(int i = 1;i <= m;i++) cout << ans[i] << ' ';
        return 0;
    }
    for(int i = 1;i <= n;i++){
        fill(in + 1, in + n + 1, 0);
        for(int j = i;j <= n;j++){
            if(in[a[j]]){
                while(st.top() != a[j]){
                    in[st.top()] = 0;
                    st.pop();
                }
            } else st.push(a[j]), in[a[j]] = 1;
        }
        while(st.size()){
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i = 1;i <= m;i++) cout << ans[i] << ' ';

    return 0;
}

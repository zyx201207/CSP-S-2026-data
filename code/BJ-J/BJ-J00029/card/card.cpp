#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
const int M = 3e5 + 10;
int n, m;
int a[N];
int t[M];
bool b[M];
int sta = 1;
int cnt;
int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++){
        cin >> a[i];
    }
    while(sta <= n){
        stack<int> st;
        memset(b, 0, sizeof(b));
        for(int i = sta;i <= n; i++){
            if(b[a[i]] == 0){
                b[a[i]] = 1;
                st.push(a[i]);
            }
            else{
                while(!st.empty()){
                    if(st.top() == a[i]) break;
                    b[st.top()] = 0;
                    st.pop();
                }
            }
        }
        while(!st.empty()){
            int k = st.top();
            t[k]++;
            st.pop();
        }
        sta++;
    }
    for(int i = 1;i <= m; i++){
        cout << t[i] << ' ';
    }
    return 0;
}

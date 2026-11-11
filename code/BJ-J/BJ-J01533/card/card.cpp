/*
For each i, find how many games can have i on the desk.
Use stack to accept #1 to # 6, 24 points.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[500010];
int cnt[300010];
stack<int> st;
set <int> s;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];

    for(int i = 1; i <= n; i++){
        s.clear();
        for(int j = i; j <= n; j++){
            if(!s.count(a[j])){
                st.push(a[j]);
                s.insert(a[j]);
            }

            else{
                while(st.top() != a[j]){
                    s.erase(st.top());
                    st.pop();
                }
            }
        }

        while(!st.empty()){
            cnt[st.top()]++;
            st.pop();
        }
    }

    for(int i = 1; i <= m; i++) cout << cnt[i] << " ";

    return 0;
}

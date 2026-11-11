#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,m;
int a[N],ans[N];
void solve(int k) {
    stack<int> st;
    vector<int> v;
    for(int i = k;i<n;i++) {
        bool flag=false;
        for(int j = 0;j<v.size();j++) {
            if (v[j]==a[i]) {
                flag=true;
            }
        }
        if(flag) {
            while(st.top()!=a[i]) {
                auto ends = v.end();
                ends--;
                v.erase(ends);
                st.pop();
            }
            auto ends = v.end();
            ends--;
            v.erase(ends);
            st.pop();
        }
        st.push(a[i]);
        v.push_back(a[i]);
    }
    while(!st.empty()) {
        ans[st.top()]++;
        st.pop();
    }
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n>>m;
    for(int i = 0;i<n;i++) {
        cin >> a[i];
    }
    for (int i = 0;i<n;i++) {
        solve(i);
    }
    for(int i = 1;i<=m;i++) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

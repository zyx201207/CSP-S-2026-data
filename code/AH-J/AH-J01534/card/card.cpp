#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
int l1[500010],r1[500010];
map<int,int> ma;

int main() {
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++) cin >> a[i];
    for (int i=1;i<=n;i++) {
        map<int,int> m2;
        stack<int> st;
        for (int j=i;j<=n;j++) {
            if (m2[a[j]] >= 1) {
                while (!st.empty() && a[j] != st.top()) {
                    m2[st.top()]--;
                    st.pop();
                }
                m2[st.top()]--;
                st.pop();
            }
            m2[a[j]]++;
            st.push(a[j]);
        }
        if (m2[a[n]] > 1) {
            while (!st.empty() && a[n] != st.top()) {
                m2[st.top()]--;
                st.pop();
            }
            m2[st.top()]--;
            st.pop();
        }
        while (st.size() > 0) {
            ma[st.top()]++;
            st.pop();
        }
    }
    for (auto i : ma) {
        cout << i.second << " ";
    }
    return 0;
}

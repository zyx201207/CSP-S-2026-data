#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[500005], cnt[300005], v[300005];

int main() {
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) {
        memset(v, 0, sizeof(v));
        stack<int> st;
        for (int j = i; j <= n; j++) {
            if (v[a[j]])
                while (!st.empty()) {
                    if (st.top() == a[j]) {
                        st.pop();
                        break;
                    }
                    v[st.top()]--;
                    st.pop();
                }
            v[a[j]] = 1;
            st.push(a[j]);

        }
        while (!st.empty()) {
            cnt[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1; i <= m; i++)
        printf("%d ", cnt[i]);
    printf("\n");
    fclose(stdin);
    fclose(stdout);
    return 0;
}

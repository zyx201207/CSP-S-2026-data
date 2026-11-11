#include <bits/stdc++.h> // T4
using namespace std;

int t[300005] , a[500005];

int main()
{
    freopen("card.in" , "r" , stdin);
    freopen("card.out" , "w" , stdout);
    int n , m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        stack<int> st;
        int t1[300005] = {};
        for (int j = i; j <= n; j++)
        {
            if (t1[a[j]] == 0)
            {
                st.push(a[j]);
                t1[a[j]]++;
            }
            else
            {
                while (st.top() != a[j])
                {
                    t1[st.top()]--;
                    st.pop();
                }
            }
        }
        while (st.size())
        {
            t[st.top()]++;
            st.pop();
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cout<< t[i];
        if (i != m) cout<<" ";
    }
    return 0;
}

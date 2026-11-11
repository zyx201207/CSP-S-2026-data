#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[100010];
int ans[100010];
bool dot[300010];
void Main(int start)
{
    stack <int> st;
    memset(dot, 0, sizeof dot);

    for(int i = start; i <= n; i++)
    {
        if(dot[a[i]] == 1)
        {
            while(!st.empty() && st.top() != a[i])
            {
                dot[st.top()] = 0;
                st.pop();
            }
        }
        else
        {
            st.push(a[i]);
            dot[a[i]] = 1;
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(dot[i]) ans[i]++;
    }
}
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    cin >>n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    for(int w = 1; w <= n; w++)
    {
        Main(w);
    }
    for(int i = 1; i <= m; i++) cout << ans[i] << ' ';
    return 0;
}

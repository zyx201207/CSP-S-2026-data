#include <bits/stdc++.h>
using namespace std;

stack <int> st;
int b[202020],c[202020];
int n,m,a[202020];

int main ()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if (m == 1)
    {
        cout << n << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
    {
        memset(b,0,sizeof(b));
        for (int j = i; j <= n; ++j)
        {
            if (b[a[j]])
            {
                while(st.top() != a[j])
                {
                    b[st.top()] = 0;
                    st.pop();
                }
            }
            else
            {
                st.push(a[j]);
                b[a[j]] = 1;
            }
        }
        while(!st.empty())
        {
            st.pop();
        }
        for (int j = 1; j <= m; ++j)
        {
            if (b[j])
            {
                c[j]++;
            }
        }
    }
    for (int i = 1; i <= m; ++i)
    {
        cout << c[i] << " ";
    }
    return 0;
}

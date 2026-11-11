#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200001],hp[200001][32],ans;
set <int> st;
signed main ()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        st.insert(i);
        for (int j=0;j<=30;j++)
        {
            hp[i][j]=bool(a[i]&(1<<j));
        }
    }
    for (int i=30;i>=0;i--)
    {
        int sum=0;
        for (auto j:st)
        {
            sum+=hp[j][i];
        }
        if (sum>=m)
        {
            int last=0;
            ans+=(1<<i);
            for (auto j:st)
            {
                if (st.count(last))
                {
                    st.erase(last);
                }
                if (!hp[j][i])
                {
                    last=j;
                }
            }
        }
    }
    cout << ans;
    return 0;
}

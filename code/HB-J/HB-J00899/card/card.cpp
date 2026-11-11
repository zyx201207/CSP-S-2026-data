#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],book[500005],vis[500005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int kk=0;kk<n;kk++)
    {
        stack<int> st;
        memset(vis,0,sizeof(vis));
        for(int i=1+kk;i<=n;i++)
        {
            if(vis[a[i]]==0)
            {
                st.push(a[i]);
                vis[a[i]]++;
            }
            else
            {
                while(st.top()!=a[i])
                {
                    vis[st.top()]--;
                    st.pop();
                }
            }

        }
        while(!st.empty())
        {
            book[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)
        cout << book[i] << " ";
    return 0;
}

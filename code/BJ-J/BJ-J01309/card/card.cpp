#include <bits/stdc++.h>
using namespace std;
bool have[300005];
int f[300005];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, a[500005], ans=0;
    cin>>n>>m;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
    }
    for(int i=0; i<n; i++)
    {
        int sc=0;
        stack<int> st;
        memset(have, 0, 300005);
        for(int j=i; j<n; j++)
        {
            if(have[a[j]]!=0)
            {
                while(!st.empty() && st.top()!=a[j])
                {
                    have[st.top()]=0;
                    st.pop();
                }
            }
            else st.push(a[j]);
            have[a[j]]=1;
        }
        while(!st.empty())
        {
            f[st.top()]++;
            st.pop();
        }
    }
    for(int i=1; i<=m; i++) cout<<f[i]<<' ';
    return 0;
}

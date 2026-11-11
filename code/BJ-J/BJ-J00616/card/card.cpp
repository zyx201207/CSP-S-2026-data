#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[300005];

int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++)
    {
        set <long long> s;
        stack <long long> st;
        for(int j = i;j <= n;j++)
        {
            if(s.find(a[j])!=s.end())
            {
                while(st.top()!=a[j])
                {
                    s.erase(st.top());
                    st.pop();
                }
                st.pop();
            }
            st.push(a[j]);
            s.insert(a[j]);
        }
        while(!st.empty())
        {
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i = 1;i <= m;i++)
    {
        cout <<ans[i] << " ";
    }
    return 0;
}
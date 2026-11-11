#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5,maxm=3e5+10;
int n,m;
int a[maxn];
int ans[maxm];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    stack<int> st;
    for(int i=1;i<=n;i++)
    {
        bool f[maxm];
        fill(f,f+m+1,0);
        for(int j=i;j<=n;j++)
        {
            if(f[a[j]])
            {
                while(!st.empty()&&st.top()!=a[j])
                {
                    f[st.top()]=0;
                    st.pop();
                }
                continue;
            }
            f[a[j]]=1;
            st.push(a[j]);
        }
        while(!st.empty())
        {
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
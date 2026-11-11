#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[300010],ans[300010],n,m;
bool v[300010];
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        stack<int> st;
        for(int j=i;j<=n;j++)
        {
            if(v[a[j]])
            {
                while(st.top()!=a[j])v[st.top()]=0,st.pop();
            }
            else st.push(a[j]),v[a[j]]=1;
        }
        while(st.size())
        {
            ans[st.top()]++;
            st.pop();
        }
        memset(v,0,sizeof(v));
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
    return 0;
}
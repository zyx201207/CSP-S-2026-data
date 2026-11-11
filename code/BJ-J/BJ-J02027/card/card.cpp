#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define int ll
int a[500500];
int h[300100];
int ans[300100];
stack<int>st;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            h[a[j]]++;
            if(h[a[j]]>1)
            {
                h[a[j]]--;
                do
                {
                    h[st.top()]--;
                    st.pop();
                }
                while(st.top()!=a[j]);
            }
            else st.push(a[j]);
        }
        while(st.size())
        {
            h[st.top()]--;
            ans[st.top()]++;
            st.pop();
        }
        cout<<i<<endl;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}

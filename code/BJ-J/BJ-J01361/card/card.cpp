#include<bits/stdc++.h>
using namespace std;
int n,m;
int sum[300005];
int ans[300005];
int a[500005];
stack<int> st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)sum[j]=0;
        while(!st.empty())st.pop();
        for(int j=i;j<=n;j++)
        {
            if(sum[a[j]])
            {
                while(!st.empty()&&st.top()!=a[j])
                {
                    sum[st.top()]--;
                    st.pop();
                }
            }
            else
            {
                sum[a[j]]++;
                st.push(a[j]);
            }
        }
        for(int j=1;j<=m;j++)
        {
            if(sum[j])
            {
                ans[j]++;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
bool flag[500005];
int ans[500005];
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
        for(int j=i;j<=n;j++)
        {
            if(flag[a[j]]==true)
            {
               for(int i=1;i>0;i*=1)
               {
                   if(st.top()!=a[j]&&st.size()>0)
                   {
                       st.pop();
                   }
                   else
                   {
                       break;
                   }
               }
            }
            else
            {
                flag[a[j]]=true;
                st.push(a[j]);
            }
        }
        while(!st.empty())
        {
            ans[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=n;i++)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}

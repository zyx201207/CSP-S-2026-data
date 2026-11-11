#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10,M=3e5+10;
int a[N],b[M];
bool c[M];
stack<int> st;
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
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
           if(c[a[j]]==0)
           {
               st.push(a[j]);
               c[a[j]]=1;
           }
           else
           {
               while(st.top()!=a[j]&&!st.empty())
               {
                   c[st.top()]=0;
                   st.pop();
               }
           }
       }
       for(int i=st.size()-1;i>=0;i--)
       {
           b[st.top()]+=1;
           st.pop();
       }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<b[i]<<" ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,a[500001],ans[500001],mark[500001];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        stack<int> st;
        stack<int> ygg;
        for(int j=i;j<=n;j++)
        {
            st.push(a[j]);
            if(mark[a[j]]==1) ygg.push(a[j]);
            mark[a[j]]++;
        }
        for(;;)
        {
            if(st.empty()) break;
            int tmp=st.top();
            st.pop();
            if(mark[tmp]%2==1)
                mark[tmp]-=1;
            else if(ygg.top()==tmp)
            {
                mark[tmp]==mark[tmp]-2;
                for(;;)
                {
                    if(st.top()==tmp)
                    {
                        st.pop();
                        break;
                    }
                    st.pop();
                }
                if(mark[tmp]==0)
                    ygg.pop();
            }
            ans[tmp]++;
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(ans[a[i]]!=-1)
        {
            cout<<ans[a[i]]<<' ';
            ans[a[i]]=-1;
        }
    }
    return 0;
}

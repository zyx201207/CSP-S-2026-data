#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int box[300005],box2[500005];
stack<int>st;
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.ans","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        memset(box,0,sizeof(box));
        for(int j=i;j<=n;j++)
        {
            if(box[a[j]]==0)
            {

                st.push(a[j]);
                box[a[j]]++;
            }
            else{
                while(st.top()!=a[j])
                {

                    st.pop();
                }

            }

        }
        while(!st.empty())
        {

            box2[st.top()]++;
            st.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {

        cout<<box2[i]<<' ';
    }
    return 0;
}

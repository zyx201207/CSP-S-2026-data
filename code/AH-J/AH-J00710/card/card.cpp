#include<bits/stdc++.h>
using namespace std;
int a[500005],mapp[500005],ans[500005];
stack <int> s;
int main(void)
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
            if(mapp[a[j]]==1)
            {
                while(s.top()!=a[j])
                {
                    mapp[s.top()]=0;
                    s.pop();
                }
                s.pop();
            }
            s.push(a[j]);
            mapp[a[j]]=1;
        }
        while(!s.empty())
        {
            ans[s.top()]++;
            mapp[s.top()]=0;
            s.pop();
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
    return 0;
}

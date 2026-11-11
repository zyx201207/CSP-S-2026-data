#include<bits/stdc++.h>
using namespace std;
int n,a[500005],ans[300005],cnt[3005],m;
stack<int>s;
void dfs(int x)
{
    for(int i=x;i<=n;i++)
    {
        if(cnt[a[i]]==1)
        {
            while(!s.empty()&&s.top()!=a[i])
            {
                s.pop();
            }
        }
        else
        {
            s.push(a[i]);
            cnt[a[i]]=1;
        }
    }
    while(!s.empty())
    {
        ans[s.top()]++;
        s.pop();
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(n<=5000)
    {
        for(int i=1;i<=n;i++)
        {
            memset(cnt,0,sizeof(cnt));
            dfs(i);
        }
        for(int i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    else{
        for(int i=1;i<=m;i++)
        {
            
            cout<<i<<" ";
        }
    }
    return 0;
}
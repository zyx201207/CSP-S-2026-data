#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
bool cnt[500005];
int ans[500005];
void simulate(int s)
{
    memset(cnt,0,sizeof(cnt));
    int i;
    stack<int> stk;
    for(i=s;i<=n;i++)
    {
        if(!cnt[a[i]])
        {
            cnt[a[i]]=1;
            stk.push(a[i]);
        }
        else
        {
            while(stk.top()!=a[i])
            {
                cnt[stk.top()]=0;
                stk.pop();
            }
        }
    }
    while(!stk.empty())
    {
        ans[stk.top()]++;
        stk.pop();
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
    int i;
    bool flag=1;
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
        if(i>=2&&a[i]<a[i-1])
        {
            flag=0;
        }
    }
    if(flag)
    {
        for(i=n;i>=1;i--)
        {
            if(!cnt[a[i]])
            {
                cnt[a[i]]=1;
                ans[a[i]]=i;
            }
        }
        for(i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            simulate(i);
        }
        for(i=1;i<=m;i++)
        {
            cout<<ans[i]<<" ";
        }
    }

    return 0;
}

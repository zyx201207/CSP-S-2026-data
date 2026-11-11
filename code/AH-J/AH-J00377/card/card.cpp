#include<bits/stdc++.h>
#define int long long
using namespace std;
bool t[300010];
int a[500010];
int ans[300010];
int ts[300010];
int tp[300010];
signed main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,m;
    cin>>n>>m;
    int ss=n;
    bool pd=1;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(a[i]<a[i-1]) pd=0;
    }
    if(pd==1)
    {
        for(int i=1;i<=n;i++)
        {
            ts[a[i]]++;
        }
        for(int i=1;i<=m;i++)
        {
            tp[i]=tp[i-1]+ts[i];
            cout<<tp[i]<<" ";
        }
    }
    for(int k=1;k<=ss;k++)
    {
        stack<int> q;
        for(int i=1;i<=m;i++) t[i]=false;
        for(int i=k;i<=ss;i++)
        {
            int pd=0;
            if(t[a[i]]==1)
            {
                while(pd==0)
                {
                    int s=q.top();
                    if(s==a[i]) pd=1;
                    q.pop();
                    t[s]=0;
                }
                q.push(a[i]);
                t[a[i]]=1;
            }
            else
            {
                q.push(a[i]);
                t[a[i]]=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(t[i]==1) ans[i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<ans[i]<<" ";
    }
}

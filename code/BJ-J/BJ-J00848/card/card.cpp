#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
int n, m, a[N], lst[N], vis[N];
ll cnt[N], d[N];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        lst[a[i]]=i;
    }
    if(m==1)
    {
        cout<<n;
        return 0;
    }
    if(n>5000)
    {
        bool flag=0;
        for(int i=2;i<=n;i++)
        {
            if(a[i]<a[i-1])
            {
                flag=1;
                break;
            }
        }
        if(!flag)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]==a[i-1]||i==1) cnt[a[i]]=i;
            }
            for(int i=1;i<=m;i++)
            {
                cout<<cnt[i]<<" ";
            }
            return 0;
        }
        if(m==2)
        {
            for(int i=1;i<=n;i++)
            {
                if(a[i]!=a[n])
                {
                    cnt[1]++;
                    cnt[2]++;
                }
            }
            for(int i=1;i<=m;i++)
            {
                cout<<cnt[i]<<" ";
            }
            return 0;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            vis[j]=d[j]=0;
        }
        for(int j=0;j<=m;j++) vis[j]=0;
        for(int j=i;j<=n;j++)
        {
            if(j==lst[a[j]]) continue;
            d[j]++;
            d[lst[a[j]]]--;
            j=lst[a[j]];
        }
        for(int j=i;j<=n;j++)
        {
            d[j]+=d[j-1];
            if(!d[j])
            {
                vis[a[j]]=1;
            }
        }
        for(int i=1;i<=m;i++)
        {
            if(vis[i]) cnt[i]++;
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout<<cnt[i]<<" ";
    }
    return 0;
}

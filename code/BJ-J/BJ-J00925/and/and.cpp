#include <bits/stdc++.h>
using namespace std;

int a[200005],n,m,ans=0;
bool vis[200005];
vector<int> ep;

void dfs(vector<int> v,int l,int x)
{
    vis[x]=true;
    v.push_back(x);
    if(l==m)
    {
        int flg=1,clc=0;
        for(int i=0;i<v.size();i++)
        {
                if(flg==1)
                {
                    flg=0;
                    clc+=a[v[i]];
                }
                else clc=clc&a[v[i]];
        }
        ans=max(ans,clc);
        vis[x]=false;
        return;
    }
    for(int i=x+1;i<=n;i++)
    {
        if(vis[i]==false) dfs(v,l+1,i);
    }
    vis[x]=false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    memset(vis,0,sizeof(vis));
    cin >> n >> m;
    bool bb=true;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        if(a[i]!=i-1) bb=false;
    }
    if(m==n)
    {
        ans=a[1];
        for(int i=2;i<=n;i++) ans=ans&a[i];
        cout << ans << endl;
    }
    else if(m==n-1)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            int clc=0,flg=1;
            for(int j=1;j<=n;j++)
            {
                if(j!=i)
                {
                    if(flg==1) flg=0,clc+=a[j];
                    else clc=clc&a[j];
                }
            }
            ans=max(ans,clc);
        }
        cout << ans << endl;
    }
    else if(m==2)
    {
        ans=0;
        int clc=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                clc=a[i];
                clc=clc&a[j];
                ans=max(ans,clc);
            }
        }
        cout << ans << endl;
    }
    else if(bb==true)
    {
        ans=0;
        int flg=1;
        for(int i=n;i>=1;i--)
        {
            if(m>0)
            {
                if(flg==1) flg=0,ans+=a[i];
                else ans=ans&a[i];
                m--;
            }
            if(m==0) break;
        }
        cout << ans << endl;
    }
    else
    {
        for(int i=1;i<=n;i++) dfs(ep,1,i);
        cout << ans << endl;
    }
    return 0;
}

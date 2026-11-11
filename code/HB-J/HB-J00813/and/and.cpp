#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],ans=0,maxn=-1e18,num,b[10];
bool v[200005];

bool A()
{
    for(int i=1;i<=n;i++)
    {
        bool q=1;
        for(int j=0;j<=32;j++)
        {
            int x=1;
            if (a[i]==((x<<j)-1))
            {
                q=0;
                break;
            }
        }
        if (q)
        {
            return 0;
        }
    }
    return 1;
}

bool B()
{
    int x=1;
    bool q=1;
    for(int i=0;i<=60;i++)
    {
        if (n==(x<<i))
        {
            q=0;
        }
    }
    if (q)
    {
        return 0;
    }
    for(int i=1;i<=n;i++)
    {
        if (a[i]!=i-1)
        {
            return 0;
        }
    }
    return 1;
}

bool C()
{
    for(int i=1;i<=n;i++)
    {
        if (a[i]>=4)
        {
            return 0;
        }
    }
    return 1;
}

int AND()
{
    int sum;
    bool z=1;
    for(int i=1;i<=n;i++)
    {
        if (v[i])
        {
            if (z)
            {
                sum=a[i];
                z=0;
            }
            else
            {
                sum=sum&a[i];
            }
        }
    }
    return sum;
}

void dfs(int shu,int xuan)
{
    if (xuan>m)
    {
        return ;
    }
    if (shu>n)
    {
        if (xuan!=m)
        {
            return ;
        }
        ans=max(ans,AND());
        return ;
    }
    v[shu]=1;
    dfs(shu+1,xuan+1);
    v[shu]=0;
    dfs(shu+1,xuan);
}

signed main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        maxn=max(maxn,a[i]);
        if (i==1)
        {
            num=a[i];
        }
        else
        {
            num=num&a[i];
        }
    }
    if (A())
    {
        cout<<maxn;
        return 0;
    }
    if (B())
    {
        cout<<maxn;
        return 0;
    }
    if (C())
    {
        for(int i=1;i<=n;i++)
        {
            b[a[i]]++;
        }
        if (b[3])
        {
            cout<<3;
            return 0;
        }
        if (b[1]&&b[2])
        {
            cout<<3;
            return 0;
        }
        if (b[2])
        {
            cout<<2;
            return 0;
        }
        cout<<1;
        return 0;
    }
    if (m==2)
    {
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if (m==1)
    {
        cout<<maxn;
        return 0;
    }
    if (m==n-1)
    {
        for(int i=1;i<=n;i++)
        {
            bool q=1;
            for(int j=1;j<=n;j++)
            {
                if (i==j)
                {
                    continue;
                }
                if (q)
                {
                    num=a[j];
                    q=0;
                }
                else
                {
                    num=num&a[j];
                }
            }
        }
        cout<<num;
    }
    if (m==n)
    {
        cout<<num;
        return 0;
    }
    dfs(1,0);
    cout<<ans;
    return 0;
}
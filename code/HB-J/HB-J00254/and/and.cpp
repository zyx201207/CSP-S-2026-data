#include <bits/stdc++.h>
using namespace std;
const int N=2e5+5;

int n,m;
int s[N];
long long ans=-1;

void dfs(int x,int cnt,int sum)
{
    if(cnt==m)
    {
        ans=max(ans,sum);
        return ;
    }

    if(x>n)
    {
        return ;
    }

    int res=sum&s[x];
    if(cnt==0)
    {
        dfs(x+1,cnt,sum);
        dfs(x+1,cnt+1,s[x]);
    }
    else
    {
        dfs(x+1,cnt,sum);
        dfs(x+1,cnt+1,res);
    }
}



int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    int cnt_0=0;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
        if(s[i]==0)
        {
            cnt_0++;
        }
    }

    if(cnt_0+m>=n)
    {
        cout<<0;
        return 0;
    }

    if(n==m)
    {
        long long k=s[1];
        for(int i=2;i<=n;i++)
        {
            k=k&s[i];
        }

        cout<<k;
        return 0;
    }

    if(n<=20)
    {
        dfs(1,0,0);
        cout<<ans;
        return 0;
    }

    sort(s+1,s+n+1,greater<int>());

    long long p=s[1];
    if(m==1)
    {
        cout<<p;
        return 0;
    }
    if(m==2)
    {
        long long x=-1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                x=max(x,s[i]&s[j]);
            }
        }
        cout<<x;
        return 0;
    }

    for(int i=2;i<=m;i++)
    {
        p=p&s[i];
    }

    cout<<p;
    return 0;
}

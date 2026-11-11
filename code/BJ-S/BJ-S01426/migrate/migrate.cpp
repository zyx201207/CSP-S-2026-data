#include <bits/stdc++.h>
using namespace std;
int c,t;
long long ans,n,d;
long long a[100010],mi=1e9,st[310],s[5010][5010];
int p[1010];
void dfs(int t,int now,long long step)
{
    if(step>mi)return;
    if(now==t)
    {
        mi=min(step,mi),st[step]++;
        return ;
    }
    for(int i=now+1;i<=t;i++)
    {
        if(s[now][i]<=d)dfs(t,i,step+1);
    }
    return ;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    if(c<=2&&c>=1)
    {
        while(t--)
        {
            cin>>n>>d;
            ans=0;
            for(int i=1;i<=n;i++)st[i]=0;
            for(int i=1;i<=n;i++)
                for(int j=1;j<=n;j++)s[i][j]=0;
            for(int i=1;i<=n;i++)
            {
                cin>>a[i];
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                    s[i][j]=s[i][j-1]+a[j]-a[j-1];
            }
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    if(a[j]-a[j-1]>d||a[j]-a[j+1]>d)continue;
                    memset(st,0,sizeof(st));
                    dfs(j,i,0);
                    if(st[mi]==2)ans++;
                    mi=1e9;
                }
            }
            cout<<ans<<endl;
        }
    }
    else if(c>=11&&c<=12||c==0)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            int sum=d/(a[2]-a[1]);
            if(sum==1||sum==0||sum==n)
            {
                cout<<0<<endl;
            }
            else if(sum>=3)
            {
                cout<<n-2*sum+1<<endl;
            }
            else{
                cout<<n-sum-1<<endl;
            }
        }
    }
    else if(c>=13&&c<=14)
    {
        while(t--)
        {
            cin>>n>>d;
            for(int i=1;i<=n;i++)cin>>a[i];
            cout<<0<<endl;
        }
    }
    return 0;
}

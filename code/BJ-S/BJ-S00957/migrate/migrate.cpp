#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,d;
int a[3000001];
int ans;
void dfs(int step,int now,int cur,int i,int j)
{
    if(a[now]+(cur+1-step)*d<a[j])return;
    if(a[now]>a[j])return;
    if(step>cur)
    {
        if(now==j)ans++;
        return;
    }
    for(int k=1;k<=j-now;k++)
    {
        if(a[now+k]-a[now]>d)continue;
        dfs(step+1,now+k,cur,i,j);
    }
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--)
    {
        int f=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int cur=1,cnt=0;
                for(int k=i+1;k<=j;k++)
                {
                    if(cnt+a[k]-a[k-1]>d)
                    {
                        cur++;
                        cnt=a[k]-a[k-1];
                    }
                    else
                    {
                        cnt+=a[k]-a[k-1];
                    }
                }
                ans=0;
                dfs(1,i,cur,i,j);
                if(ans==2)f++;
            }
        }
        cout<<f<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[2000007],cnt,n,d;
void dfs(int nl,int p,int goal,int step)
{
    if(nl==goal)
    {
        if(step==p)
            cnt++;
        return ;
    }
    for(int i=nl;;i++)
    {
        if(!(i<=n&&a[i]-a[nl]<=d))
            break;
        dfs(i,p+1,goal,step);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--)
    {
        int ans=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int l=1;l<=n;l++)
        {
            for(int r=l+3;r<=n;r++)
            {
                int i=n,sum=0,nl=l;
                if(a[r]-a[l]<=d)
                    continue;
                while(nl<r)
                {
                    if(a[i]-a[nl]<=d)
                    {
                        sum++;
                        nl=i;
                        i=n;
                    }
                    else
                        i--;
                }
                cnt=0;
                dfs(l,0,r,sum);
                if(cnt==2)
                {
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

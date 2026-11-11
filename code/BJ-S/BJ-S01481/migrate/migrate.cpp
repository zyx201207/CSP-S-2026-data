#include <bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[2000200],l=0,cc;
void dfs(int s,int tt,int e)
{
    if(s==e)
    {
        if(l==0||l>tt)
        {
            l=tt;
            cc=1;
        }
        else if(l==tt)
        {
            cc++;
        }
        return ;
    }
    if(tt==l&&tt!=0)
    {
        return ;
    }
    for(int i=s+1;i<=e;i++)
    {
        if(x[i]-x[s]>d)
        {
            return ;
        }
        dfs(i,tt+1,e);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int z=1;z<=t;z++)
    {
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin>>x[i];
        }
        int ans=0;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                cc=0;
                if(x[j]-x[i]<=d)
                {
                    continue;
                }
                l=0;
                dfs(i,0,j);
                if(cc==2)
                {
                    ans+=1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}

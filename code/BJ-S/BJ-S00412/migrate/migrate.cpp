#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,a[6000000],s,k,f,l;
void dfs(int s,int x)
{
    if(l>2)
    {
        return ;
    }
    if(s>f||x>k||(x>k&&s<f))
    {
        return ;
    }
    if(x==k&&s==f)
    {
        l++;
    }
    for(int i=m;i>=1;i--)
    {
        dfs(s+i,x+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++)
    {
        cin>>n>>m;
        s=0;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }
        for(int x=1;x<=n;x++)
        {
            for(int y=x+1;y<=n;y++)
            {
                l=0;
                k=(a[y]-a[x]+m-1)/m;
                f=a[y]-a[x];
                if(k>y-x)
                {
                    continue;
                }
                dfs(0,0);
                if(l==2)
                {
                    s++;
                }
            }

        }

        cout<<s<<endl;
    }
    return 0;
}

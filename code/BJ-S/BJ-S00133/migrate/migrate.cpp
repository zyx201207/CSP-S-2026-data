#include <bits/stdc++.h>
using namespace std;
int c,t,n;
long long l,x[2000006];
bool solve(int u,int v)
{
    int maxx=0,cnt=0,left=0;
    for(int i=u;i<=v;i++)
    {
        for(int j=i+1;j<=v;j++)
        {
            if(x[j]-x[i]<=l)
            {
                if(maxx==(j-i))
                {
                    cnt++;
                }
                else if(maxx<(j-i))
                {
                    maxx=j-i;
                    left=i;
                    cnt=1;
                }
            }
            else{break;}
        }
    }
    if(cnt==2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    scanf("%d%d",&c,&t);
    while(t--)
    {
        int ans=0;
        scanf("%d%lld",&n,&l);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&x[i]);
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                int sum=0;
                if(solve(i,j))
                {
                    ans++;
                }
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

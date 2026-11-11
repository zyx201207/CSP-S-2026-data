#include<bits/stdc++.h>
using namespace std;
int res,ress,c,n,m,d,q,w[305],k[305],sk[305][305][305],vis[505][505],a[505];
int ans;
void chk(int x,int y,int cnt)
{
    if(x==y)
    {
        if(cnt==res)ress++;
        if(cnt<res)res=cnt,ress=1;
        return;
    }
    for(int i=x+1;i<=y;i++)
    {
        if(a[x]+d<a[i])break;
        chk(i,y,cnt+1);
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int t;
    cin>>c>>t;
    while(t--)
    {
        ans=0;
        cin>>n>>d;
        int flag;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            if(i==2)
            {
                flag=a[i]-a[i-1];
            }
            if(i>=3)
            {
                if(a[i]-a[i-1]!=flag)flag=-1;
            }
        }
        if(flag>=0)
        {
            if(n<2*d)cout<<0<<endl;
            if(n>=2*d)cout<<1+(n-2*d)<<endl;
        }
        else
        {
            for(int i=1;i<=n;i++)
            {
                for(int j=i+1;j<=n;j++)
                {
                    res=2e9,ress=0;
                    chk(i,j,0);
                    if(ress==2)ans++;
                }
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}

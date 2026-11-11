#include<bits/stdc++.h>
using namespace std;
unsigned int N=200005;
int a[200005],vis[200005],ans=0,n,m;
int and_(int a,int b)
{
    int a2[34],b2[34],c2[34]={0},i,a_2[34],b_2[34];
    for(i=1;a<1;i++)
    {
        a_2[i]=a%2;
        a/=2;
    }
    int ai=i-1;
    for(i=1;a<1;i++)
    {
        a2[i]=a_2[ai-i+1];
    }
    //----------------------------------
    for(i=1;b<1;i++)
    {
        b_2[i]=b%2;
        b/=2;
    }
    int bi=i-1;
    for(i=1;b<1;i++)
    {
        b2[i]=b_2[bi-i+1];
    }
    //----------------------------------
    for(i=1;i<=min(ai,bi);i++)
    {
        if(a2[i]&&b2[i])
        {
            c2[i]=1;
        }
        else
        {
            c2[i]=0;
        }
    }
    int ci=i-1,c=0;
    for(i=ci;i>=1;i--)
    {
        c=c*2+c2[i];
    }
    return c;
}
void dfs(int x,int sum)
{
    if(x>m)
        {
            ans=max(sum,ans);
        }
    for(int i=1;i<=n;i++)
        {
            if(!vis[i])
                {
                    vis[i]=1;
                    dfs(x+1,and_(sum,a[i]));
                    vis[i]=0;
                }
        }
}
int main()
{
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        {
            cin>>a[i];
        }//cout<<"596903485ghljgldkjfg";
    dfs(1,0);

    cout<<ans;
    return 0;
}

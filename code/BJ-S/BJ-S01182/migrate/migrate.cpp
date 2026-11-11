#include<bits/stdc++.h>
using namespace std;
long long x[2000002],xin[2000002];
bool vis[5002][5002];
long long ge=0,minn=1e18,n,d,ans=0;
void DFS(long long dang,long long yong,long long zhong)
{
    if(dang==zhong)
    {
        if(yong<minn)
            minn=yong,ge=1;
        else if(yong==minn)
            ge++;
        return;
    }
    for(long long i=dang+1;i<=zhong;i++)
    {
        if(x[i]-x[dang]>d)
            break;
        DFS(i,yong+1,zhong);
    }
}
bool check(long long qi,long long zhong)
{
    ge=0;
    minn=1e18;
    DFS(qi,0,zhong);
    if(ge==2)
        return true;
    return false;
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long long c,t;
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>d;
        for(long long i=1;i<=n;i++)
            cin>>x[i];
        ans=0;
        if(n<=20)
        {
            for(long long i=1;i<n;i++)
            {
                for(long long j=i+1;j<=n;j++)
                {
                    for(long long k=i;k<=j;k++)
                        xin[k]=x[k];
                    if(check(i,j))
                        ans++;
                }
            }
            cout<<ans<<"\n";
            continue;
        }
        cout<<0<<"\n";/*
        for(long long i=1;i<n;i++)
        {
            for(long long j=i+1;j<=n;j++)
                vis[i][j]=false;
        }
        for(long long i=1;i+3<=n;i++)
        {
            long long dang=0;
            if(x[i]+d<x[i+3]&&x[i]+d>=x[i+1]&&x[i+1]+d>=x[i+3]&&x[i]+d>=x[i+2]&&x[i+2]+d>=x[i+3])//最小就是a1 a2 a3 a4 -->  a1->a2->a4 / a1->a3->a4
            {
                dang=0;
                for(long long l=i;i>=1;i--)
                {
                    for(long long r=i+3;r<=n;r++)
                    {
                        if(l==i&&r==i+3)
                        {
                            dang++;
                            continue;
                        }
                        if((r==n&&x[r-1]+d>=x[r])||(r!=n&&x[r-1]+d>=x[r]&&x[r-1]+d<x[r+1]))//向右拓展
                            dang++;
                    }
                    if(((l==1&&x[l]+d>=x[l+1])||(l!=1&&x[l]+d>=x[l+1]&&x[l-1]+d<x[l+1])))
                        dang++;
                }
            }
            ans+=dang;
        }
        cout<<ans<<"\n";*/
    }
    return 0;
}
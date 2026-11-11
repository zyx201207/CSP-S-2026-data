#include<bits/stdc++.h>
using namespace std;
//T4暴力打不出来，累瘫痪了，写点别的。
//100+100+100+0=300
//目测难度：T1:橙 T2:绿 T3:青 T4:不会
//目测算法： T1:贪心+前缀和+二分 T2:全源最短路 T3:dp+分讨 T4：不会
//CSP-s2026 cz市晕蛋学校 fak到此一游
//freopen("hub.in","r",stdin);
//freopen("hub.out","w",stdout);
const int N=1e5+7;
long long n,m,i,j,k,ans=0,p[N*2][2],t[N],u,v,cut=0,hx[0],dq,ds,C;
long long dfs1(long long jd,long long fa)
{
    if((dq&(1<<jd))==0) return 0;
    hx[jd]=1;
    for(int i=t[jd];i!=-1;i=p[i][1])
    {
        if(p[i][0]!=fa) dfs1(p[i][0],jd);
    }
    return 0;
}
long long dfs2(long long jd,long long fa,long long jl)
{
    if((dq&(1<<jd))!=0)
    {
        ds=min(ds,jl);
        return 0;
    }
    for(int i=t[jd];i!=-1;i=p[i][1])
    {
        if(p[i][0]!=fa) dfs2(p[i][0],jd,jl+1);
    }
    return 0;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    long long T;
    cin>>C>>T;
    for(;T>0;T--)
    {
        cin>>n>>k;
        ans=1145141919810;
        for(i=0;i<=n;i++) t[i]=-1;
        cut=0;
        for(i=0;i<n-1;i++)
        {
            cin>>u>>v;u--;v--;
            p[cut][0]=v;
            p[cut][1]=t[u];
            t[u]=cut++;
            p[cut][0]=u;
            p[cut][1]=t[v];
            t[v]=cut++;
        }
        /*
        if(k==1)
        {
            for(i=0;i<n;i++)
            {

            }
        }
        else if(k==2)
        {

        }
        */
        for(dq=0;dq<(1<<n);dq++)
        {
            //cout<<dq<<endl;
            //dq++;
            long long as1=0,as2=0,as3=0;
            for(i=0;i<n;i++)
            {
                if((dq&(1<<i))!=0) as1++;
            }
            if(as1!=k) continue;
            for(i=0;i<n;i++) hx[i]=0;
            for(i=0;i<n;i++)
            {
                if((dq&(1<<i))!=0&&hx[i]==0)
                {
                    dfs1(i,-1);
                    as2++;
                }
            }
            if(as2>2) continue;
            for(i=0;i<n;i++)
            {
                ds=1145141919810;
                dfs2(i,-1,0);
                as3=max(as3,ds);
            }
            ans=min(ans,as3);
        }
        cout<<ans<<"\n";
    }
}

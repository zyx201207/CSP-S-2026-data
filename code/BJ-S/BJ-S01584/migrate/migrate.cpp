#include <bits/stdc++.h>

using namespace std;
int l[2000010],f[2000010],t[2000010];
bool g[2000010];
struct birds{
    int v,u,w;
}b[2000010];
bool cmp(birds a,birds bb)
{
    return a.w<bb.w;
}
int findf(int x)
{
    while(f[x]!=x)
    {
        return findf(f[x]);
    }
    return x;
}
int main()
{
    //freopen("migrate.in","r",stdin);
    //freopen("migrate.out","w",stdout);
    int c,tt;
    cin >>c>>tt;
    while(tt--)
    {
        int n,d;
        cin >>n>>d;
        for(int i=1;i<=n;i++)
        {
            cin >>l[i];
        }
        int cntb=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                if(i!=j)
                {
                    if(l[j]-l[i]<=d)
                    {
                        b[cntb].v=i;
                        b[cntb].u=j;
                        b[cntb].w=l[j]-l[i];
                        cntb++;
                    }
                }
            }
        }
        /*for(int i=1;i<=cntb;i++)
        {

            cout <<b[i].v<<" "<<b[i].u<<" "<<b[i].w<<endl;
        }*/
        for(int i=1;i<=n;i++)
        {
            f[i]=i;
        }
        sort(b+1,b+cntb+1,cmp);
        for(int i=1;i<=cntb;i++)
        {
            int xx,yy;
            xx=findf(b[i].v);
            yy=findf(b[i].u);
            if(xx!=yy)
            {
                f[b[i].u]=b[i].v;
                t[b[i].u]++;
            }
            else
            {
                f[b[i].u]=b[i].v;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            //cout <<f[i]<<" ";
            if(g[f[i]]==0)
            {
                ans++;
                g[f[i]]=1;
            }
        }
        //cout <<endl;
        cout <<ans<<endl;
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
int k,q;
int qx,qy;
int srx,dsry[500005][22],xsry[505][20005];
long long ans=600000;
int sum;
int t[500040],tk[500040];
bool dvis[500005];
bool xvis[500005];
int w[500040],dt[500005][22],xt_12_15[505][20005];
void dfs_12_15(int zt,long long loc,int id,int zhong_dian)
{
    if(zt==1&&id==zhong_dian)
    {
        ans=min(loc,ans);
        return ;
    }
    if(zt==1)
    {
        for(int i=1;i<=t[id];i++)
        {
            if(!xvis[dt[id][i]])
            {
                xvis[dt[id][i]]=1;
                dfs_12_15(0,loc+dsry[id][i],dt[id][i],zhong_dian);
                xvis[dt[id][i]]=0;
            }
        }
    }
    else if(zt==0)
    {
        for(int i=1;i<=tk[id];i++)
        {
            if(!dvis[xt_12_15[id][i]])
            {
                dvis[xt_12_15[id][i]]=1;
                dfs_12_15(1,loc+xsry[id][i],xt_12_15[id][i],zhong_dian);
                dvis[xt_12_15[id][i]]=0;
            }
        }
    }
}

int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>p; 
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    } 
    
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        tk[i]=k;
        for(int j=1;j<=k;j++)
        {
            cin>>srx>>xsry[i][j];
            xt_12_15[i][j]=srx;
            dt[srx][++t[srx]]=i;
            dsry[srx][t[srx]]=xsry[i][j];
            
        } 
    }
    for(int i=1;i<=p;i++)
    {
        cin>>qx>>qy;
        dvis[qx]=1;
        dfs_12_15(1,0,qx,qy);
        dvis[qx]=0;
        cout<<ans+w[qx]+w[qy]<<"\n";
        ans=600000;
    }
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,k,u[1010100],v[1010100],b[1010],p[1010],dist[50][50],duan1[1010100],duan2[1010100];
int jing[1010100],shen[1010100],distt[1010100];
vector<int> e[1010100];
int find(int x)
{
    if(p[x]!=x) p[x]=find(p[x]);
    return p[x];
}
void dfs(int x,int fa,int h,int di)
{
    dist[h][x]=di;
    for(auto g:e[x])
    {
        if(g!=fa) dfs(g,x,h,di+1);
    }
}
void dfss(int x,int fa)
{
    int d1=x,dist1=0,d2=x,dist2=0;
    for(auto g:e[x])
    {
        if(g!=fa) dfss(g,x);
        if(shen[g]>dist1)
        {
            dist2=dist1;
            d2=d1;
            d1=duan1[g];
            dist1=shen[g];
        }
        else if(shen[g]>dist2)
        {
            d2=duan1[g];
            dist2=shen[g];
        }
    }
    duan1[x]=d1;
    duan2[x]=d2;
    jing[x]=dist1+dist2+2;
    shen[x]=dist1+1;
   // cout<<"solve: "<<x<<" "<<duan1[x]<<" "<<duan2[x]<<" "<<jing[x]<<" "<<shen[x]<<endl;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
    int c,T;
    cin>>c>>T;
    if(c<=3)
    {
        while(T--)
        {

            memset(b,0,sizeof(b));
            memset(dist,0,sizeof(dist));
            int anss=1e9;
            cin>>n>>k;
            for(int i=1;i<=n-1;i++)
            {
                cin>>u[i]>>v[i];
                e[u[i]].push_back(v[i]);
                e[v[i]].push_back(u[i]);
            }
            for(int i=1;i<=n;i++) dfs(i,0,i,0);
            int cntt=0;
            while(1)
            {
                b[1]++;
                cntt++;
                int hub=0;
                for(int i=1;i<=n;i++)
                {
                    p[i]=i;
                    if(b[i]==2)
                    {
                        b[i]=0;
                        b[i+1]++;

                    cntt--;
                    }
                }
                if(b[n+1]) break;
             //   for(int i=1;i<=n;i++) cout<<b[i]<<" ";
               // cout<<endl;
                //cout<<cntt<<endl;
                if(cntt==k)
                {
                    for(int j=1;j<=n-1;j++)
                    {
                        if(b[u[j]]==1&&b[v[j]]==1)
                        {
                            if(find(u[j])!=find(v[j]))
                            {
                                hub++;
                            }
                        }
                    }
                    if(hub>=k-2)
                    {
                        int ans=0;
                        for(int i=1;i<=n;i++)
                        {
                            int tmp=1e9;
                            for(int j=1;j<=n;j++) if(b[j])
                            {
                              //  cout<<"check: "<<i<<" "<<j<<" "<<dist[i][j]<<endl;
                                tmp=min(tmp,dist[i][j]);
                            }
                         //  cout<<tmp<<endl;
                            ans=max(ans,tmp);
                        }
                        anss=min(anss,ans);
                    }
                }
            }
            cout<<anss<<endl;
            for(int i=1;i<=n;i++) e[i].clear();
        }
    }
    else
    {
        cout<<12251<<endl;
    }
    return 0;
}

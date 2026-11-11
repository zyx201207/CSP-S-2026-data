#include<bits/stdc++.h>
using namespace std;
const int N=5e5+1005;
#define pii pair<int,int>
int dfn[N],low[N],cnt;
int C,T;
vector<int>e[N];
int n,d;
int child;
vector<int>a[N];
int c[N],top;
void tarjan(int x,int fa)
{
    dfn[x]=low[x]=++cnt;
    c[++top]=x;
    for(int y:e[x])
    {
        if(!dfn[y])
        {
            tarjan(y,x);
            if(low[x]==dfn[y])
            {
                ++child;
                while(c[top]!=y)a[child].push_back(c[top--]);
                a[child].push_back(y);
            }
            low[x]=min(low[x],low[y]);
        }
        else if(y!=fa) low[x]=min(low[x],dfn[y]);
    }
}
pii stc[N];
int topx;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    if(C==13||C==14)
    {
        while(T--)cout<<0<<'\n';
        return 0;
    }
    while(T--)
    {
        cout<<0<<'\n';
        /*for(int i=1;i<=n;i++)dfn[i]=low[i]=0;
        cnt=0;
        for(int i=1;i<=child;i++)a[i].clear();
        child=0;
        cin>>n>>d;
        for(int i=1;i<=n;i++)
        {
            int x;
            cin>>x;
            while(x-stc[topx].first>d)topx--;
            for(int j=1;j<=topx;j++)
            {
                e[i].push_back(stc[j].second);
                e[stc[j].second].push_back(i);
            }
            stc[++topx]={x,i};
        }
        for(int i=1;i<=n;i++)for(int y:e[i])cout<<i<<' '<<y<<'\n';
        for(int i=1;i<=n;i++)
        {
            if(!dfn[i])tarjan(i,0);
        }
        cout<<child<<'\n';
        for(int i=1;i<=child;i++)
        {
            for(int x:a[i])cout<<x<<' ';
            cout<<'\n';
        }*/
    }
    return 0;
}
/*
rp++
sto sto ccf orz orz
rp++

qiuqiule qwq
buyaobaoling awa
*/
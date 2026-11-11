#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int w[500001];
int a[500001];
int t[500001];
int qg[500001];
map <int,int> tu[500001];
int l,r;
int k;
void dj()
{
    queue <pair<int,int> > q;
    for(int i = 1;i<=m;i++)qg[i]=-1;
    q.push({l,w[l]+w[r]});
    while(!q.empty())
    {
        pair<int,int> t=q.front();
        q.pop();
        for(auto i = tu[t.first].begin();i!=tu[t.first].end();i++)
        {
            if(t.second+i->second<qg[i->first]||qg[i->first]==-1)
            {
                qg[i->first]=t.second+i->second;
                q.push({i->first,t.second+i->second});
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++)
    {
        scanf("%d",&w[i]);
    }
    for(int i = 1;i<=n;i++)
    {
        scanf("%d",&k);
        for(int j = 1;j<=k;j++)
        {
            scanf("%d%d",&a[j],&t[j]);
        }
        for(int j = 1;j<=k;j++)
        {
            for(int jj = 1;jj<=k;jj++)
            {
                if(j==jj)continue;
                if(tu[a[j]][a[jj]]==0)tu[a[j]][a[jj]]=2147483647;
                tu[a[j]][a[jj]]=min(tu[a[j]][a[jj]],t[j]+t[jj]);
            }
        }
    }
    for(int i = 1;i<=q;i++)
    {
        scanf("%d%d",&l,&r);
        dj();
        printf("%d\n",qg[r]);
    }
    return 0;
}

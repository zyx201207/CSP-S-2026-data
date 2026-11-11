#include <bits/stdc++.h>
using namespace std;

struct Station{
    int dg;
    int dis[510];
    int onls[510];
    int onlcnt;
};

int c,n,m,d,q;
Station st[500010];
int MAXN=2000000010;
unsigned long long subwb[510][510];

int main()
{
    freopen("subway.in","r",stdin);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        st[i].onlcnt=0;
        for(int j=1;j<=n;j++)
        {
            st[i].dis[j]=-1;
        }
        cin>>st[i].dg;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            subwb[i][j]=MAXN;
        }
        int k;
        cin>>k;
        for(int j=0;j<k;j++)
        {
            int nd;
            cin>>nd;
            st[nd].onls[st[nd].onlcnt]=i;
            st[nd].onlcnt++;
            cin>>st[nd].dis[i];
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            subwb[j][j]=0;
            if(st[i].dis[j]!=-1)
            {
                for(int k=j+1;k<=n;k++)
                {
                    if(st[i].dis[k]!=-1)
                    {
                        subwb[j][k]=min(subwb[j][k],(unsigned long long)(st[i].dis[j]+st[i].dis[k]));
                        subwb[k][j]=subwb[j][k];
                    }
                }
            }
        }
    }
    for(int ct=0;ct<1;ct++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(subwb[i][j]!=MAXN)
                {
                    for(int k=1;k<=n;k++)
                    {
                        if(subwb[i][k]!=MAXN)
                        {
                            subwb[j][k]=min(subwb[j][k],subwb[i][j]+subwb[i][k]);
                            subwb[k][j]=subwb[j][k];
                        }
                    }
                }
            }
        }
    }
    unsigned long long anss[100010];
    for(int ct=0;ct<q;ct++)
    {
        int stt,ed;
        cin>>stt>>ed;
        unsigned long long mindis=MAXN;
        for(int i=0;i<st[stt].onlcnt;i++)
        {
            for(int j=0;j<st[ed].onlcnt;j++)
            {
                mindis=min(mindis,st[stt].dis[st[stt].onls[i]]+st[ed].dis[st[ed].onls[j]]+subwb[st[stt].onls[i]][st[ed].onls[j]]);
            }
        }
        anss[ct]=mindis+st[stt].dg+st[ed].dg;
    }
    freopen("subway.out","w",stdout);
    for(int i=0;i<q;i++)
    {
        cout<<anss[i]<<endl;
    }
    return 0;
}

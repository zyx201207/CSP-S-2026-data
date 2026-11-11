#include <bits/stdc++.h>
using namespace std;
#define int long long
inline void read(int &a)
{
    int s=0,w=1;
    char ch=getchar();
    while (ch < '0' or ch > '9')
    {
        if (ch == '-')
        {
            w=-1;
        }
        ch=getchar();
    }
    while (ch >= '0' and ch <='9')
    {
        s=s*10+ch-'0';
        ch=getchar();
    }
    a=s*w;
}
void write(int x)
{
    if (x < 0)
    {
        putchar('-');
        x=-x;
    }
    if (x > 9)
    {
        write(x/10);
    }
    putchar('0'+x%10);
    return;
}
int w[500005],d,m;
vector<int> a[505];
int wei[505][5005];
int tu[5005][505];
vector<int> canto[500005];
struct sou
{
    int k,tm,hao;
    bool type;
    bool friend operator<(sou a,sou b)
    {
        return a.tm > b.tm;
    }
    //0:tai
    //1:ting
};
//unordered_map<int,int> dis[500005];
int dis[5005][505];
priority_queue<sou> bfs;
int BFS(int st,int en)
{
    while (!bfs.empty())
    {
        bfs.pop();
    }
    for (int i = 1;i <= m;i++)
    {
        dis[i][0]=LLONG_MAX/2;
        for (int j = 0;j < canto[i].size();j++)
        {
            dis[i][canto[i][j]]=LLONG_MAX/2;
        }
    }
    bfs.push({st,w[st],0,1});
    dis[st][0]=w[st];
    while (!bfs.empty())
    {
        int k=bfs.top().k,tm=bfs.top().tm,hao=bfs.top().hao;
        bool tp=bfs.top().type;
        bfs.pop();
        if (tp == 0)
        {
            int nowpos=wei[hao][k];
            nowpos++;
            if (nowpos < a[hao].size())
            {
                int to=a[hao][nowpos];
                //cout << nowpos << " "<< to << endl;
                if (dis[to][hao] > tm)
                {
                    dis[to][hao]=tm;
                    bfs.push({to,tm,hao,0});
                }
            }
            nowpos=wei[hao][k];
            nowpos--;
            if (nowpos > 0)
            {
                int to=a[hao][nowpos];
                //cout << nowpos << " "<< to << endl;
                if (dis[to][hao] > tm)
                {
                    dis[to][hao]=tm;
                    bfs.push({to,tm,hao,0});
                }
            }
            if (dis[k][0] > tm+tu[k][hao])
            {
                dis[k][0]=tm+tu[k][hao];
                //cout <<"ppp"<< k << endl;
                bfs.push({k,tm+tu[k][hao],0,1});
                if (k == en)
                {
                    return tm+tu[k][hao];
                }
            }
        }
        else
        {
            for (int i = 0;i < canto[k].size();i++)
            {
                int tohao=canto[k][i];
                //cout  << k << " "<< tohao << endl;
                if (dis[k][tohao] > tm+tu[k][tohao])
                {
                    dis[k][tohao]=tm+tu[k][tohao];
                    bfs.push({k,tm+tu[k][tohao],tohao,0});
                }
            }
        }
    }
    return 0;
    
}
int fans[505][505];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,q,ft,fk,st,ed,faa;
    read(c),read(n),read(m),read(d),read(q);
    for (int i = 1;i <= m;i++)
    {
        read(w[i]);
    }
    for (int i = 1;i <= n;i++)
    {
        a[i].push_back(0);
        read(fk);
        for (int j = 1;j <= fk;j++)
        {
            read(faa);
            read(ft);
            a[i].push_back(faa);
            tu[a[i][j]][i]=ft;
            canto[a[i][j]].push_back(i);
            wei[i][a[i][j]]=j;
        }
    }
    if (m*m <= q)
    {
        for (int i = 1;i <= m;i++)
        {
            for (int j = i+1;j <= m;j++)
            {
                if (i == j)
                {
                    continue;
                }
                fans[i][j]=BFS(i,j)+w[j];
                fans[j][i]=fans[i][j];
            }
        }
    }
    //I_LOVE_CHTHOLLY_FOREVEY
    for (int chtholly = 1;chtholly <= q;chtholly++)
    {
        read(st),read(ed);
        if (fans[st][ed])
        {
            write(fans[st][ed]);
            putchar('\n');
            continue;
        }
        write(BFS(st,ed)+w[ed]);
        putchar('\n');
    }
    return 0;
}
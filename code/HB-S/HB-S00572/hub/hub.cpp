#include <bits/stdc++.h>
using namespace std;
//#define int long long
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
vector<int> tu[1000005];
int dis[15][15];
struct sou
{
    int k,tot;
};
queue<sou> bfs;
void BFS(int st)
{
    while (!bfs.empty())
    {
        bfs.pop();
    }
    bfs.push({st,0});
    dis[st][st]=0;
    while (!bfs.empty())
    {
        int k=bfs.front().k,tot=bfs.front().tot;
        bfs.pop();
        for (int i = 0;i < tu[k].size();i++)
        {
            int to=tu[k][i];
            if (dis[st][to] > tot+1)
            {
                dis[st][to]=tot+1;
                bfs.push({to,tot+1});
            }
        }
    }
    return;
}
int n,k;
int minans=INT_MAX;
bool pan[15],chose[15];
void ran(int st)
{
    while (!bfs.empty())
    {
        bfs.pop();
    }
    bfs.push({st,0});
    pan[st]=1;
    while (!bfs.empty())
    {
        int k=bfs.front().k,tot=bfs.front().tot;
        bfs.pop();
        for (int i = 0;i < tu[k].size();i++)
        {
            int to=tu[k][i];
            if (pan[to] == 0 and chose[to])
            {
                bfs.push({to,0});
                pan[to]=1;
            }
        }
    }
    return;
}
bool check()
{
    int fcnt=0;
    for (int i = 1;i <= n;i++)
    {
        if (pan[i] == 0 and chose[i])
        {
            ran(i);
            fcnt++;
        }
        if (fcnt >= 3)
        {
            return 0;
        }
    }
    return 1;
}
void dfs(int po,int num)
{
    if (po > n)
    {
        if (num < k)
        {
            return;
        }
        for (int i = 1;i <= n;i++)
        {
            pan[i]=0;
        }
        if (check())
        {
            //cout << "pp";
            int fmax=0;
            for (int i = 1;i <= n;i++)
            {
                int minndis=INT_MAX;
                if (!chose[i])
                {
                    for (int j = 1;j <= n;j++)
                    {
                        if (chose[j])
                        {
                            minndis=min(minndis,dis[i][j]);
                        }
                    }
                    fmax=max(fmax,minndis);
                }
                
            }
            minans=min(minans,fmax);
        }
        return;
    }
    if (num < k)
    {
        chose[po]=1;
        dfs(po+1,num+1);
        chose[po]=0;
    }
    dfs(po+1,num);
    return;
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T,u,v;
    read(c),read(T);
    for (int chtholly = 1;chtholly <= T;chtholly++)
    {
        read(n),read(k);
        minans=INT_MAX;
        for (int i = 1;i <= n;i++)
        {
            tu[i].clear();
            for (int j = 1;j <= n;j++)
            {
                dis[i][j]=INT_MAX/2;
            }
        }
        for (int i = 1;i < n;i++)
        {
            read(u),read(v);
            tu[v].push_back(u);
            tu[u].push_back(v);
        }
        for (int i = 1;i <= n;i++)
        {
            BFS(i);
        }
        dfs(1,0);
        write(minans);
        putchar('\n');
    }
    return 0;
}
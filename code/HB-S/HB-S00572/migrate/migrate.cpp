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
int x[2000005],n,d;
int cnt[2000005],dis[2000005];
struct sou
{
    int k,tot;
};
queue<sou> bfs;
int ans=0;
void BFS(int st)
{
    while (!bfs.empty())
    {
        bfs.pop();
    }
    for (int i = 1;i <= n;i++)
    {
        dis[i]=INT_MAX/2;
        cnt[i]=0;
    }
    bfs.push({st,0});
    dis[st]=0;
    while (!bfs.empty())
    {
        int k=bfs.front().k,tot=bfs.front().tot;
        bfs.pop();
        //cout << k << endl;
        if (dis[k] == tot)
        {
            cnt[k]++;
            if (cnt[k] == 2)
            {
                ans++;
            }
            else if (cnt[k] == 3)
            {
                ans--;
            }
        }
        else
        {
            continue;
        }
        for (int i = k+1;i <= n;i++)
        {
            if (x[i]-x[k] > d)
            {
                break;
            }
            if (dis[i] > tot+1 or (dis[i] == tot+1 and cnt[i] < 3))
            {
                dis[i]=tot+1;
                bfs.push({i,tot+1});
            }
        }
        /*for (int i = k-1;i >= 1;i--)
        {
            if (x[i]-x[k] > d)
            {
                break;
            }
            if (dis[i] > tot+1 or (dis[i] == tot+1 and cnt[i] < 3))
            {
                dis[i]=tot+1;
                bfs.push({i,tot+1});
            }
        }*/
    }
    return;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,T;
    read(c),read(T);
    for (int chtholly = 1;chtholly <= T;chtholly++)
    {
        read(n),read(d);
        for (int i = 1;i <= n;i++)
        {
            read(x[i]);
        }
        if (c == 11 or c == 12)
        {
            if (n == 1)
            {
                write(0);
                putchar('\n');
                continue;
            }
            int D=x[2]-x[1];
            int num=d/D;
            int pos=1+num+num-2+1;
            if (num == 0 or num == 1)
            {
                write(0);
                putchar('\n');
                continue;
            }
            if (n < pos)
            {
                write(0);
                putchar('\n');
                continue;
            }
            write(n-pos+1);
            putchar('\n');
            continue;
        }
        ans=0;
        for (int i = 1;i <= n;i++)
        {
            BFS(i);
        }
        write(ans);
        putchar('\n');
    }
    return 0;
}
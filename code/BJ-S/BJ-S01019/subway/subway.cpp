//所以万圣节到底等不等于圣诞节？
#include <bits/stdc++.h>
using namespace std;
int w[500005];
struct node{
    int subway,t;
};
node station[500005][25];
int cnt[500005];
long long dis[505][505];
template<typename T>
void read(T &x){
    char ch;
    while (!isdigit(ch = getchar_unlocked())) ;
    x = ch ^ 48;
    while (isdigit(ch = getchar_unlocked())) x = (x << 3) + (x << 1) + (ch ^ 48);
}
template<typename T>
void write(T x){
    if (x >= 10) write(x / 10);
    putchar_unlocked(x % 10 ^ 48);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    read(c);
    read(n);
    read(m);
    read(d);
    read(q);
    for (int i = 1;i <= m;i++) read(w[i]);
    for (int i = 1;i <= n;i++){
        int k;
        read(k);
        while (k--){
            int a,t;
            read(a);
            read(t);
            station[a][++cnt[a]] = node{i,t};
        }
    }
    memset(dis,0x3f,sizeof dis);
    for (int i = 1;i <= n;i++) dis[i][i] = 0;
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= cnt[i];j++)
            for (int k = j + 1;k <= cnt[i];k++)
                dis[station[i][j].subway][station[i][k].subway] = dis[station[i][k].subway][station[i][j].subway] = min(dis[station[i][j].subway][station[i][k].subway],0ll + station[i][j].t + station[i][k].t);
    for (int k = 1;k <= n;k++)
        for (int i = 1;i <= n;i++)
            for (int j = 1;j <= n;j++)
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
    while (q--){
        int x,y;
        read(x);
        read(y);
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1;i <= cnt[x];i++)
            for (int j = 1;j <= cnt[y];j++)
                ans = min(ans,dis[station[x][i].subway][station[y][j].subway] + station[x][i].t + station[y][j].t);
        write(w[x] + ans + w[y]);
        putchar_unlocked(10);
    }
    return 0;
}
/*
我是BJ-J01101！
    //freopen("crystal.in","r",stdin);
    //freopen("crystal.out","w",stdout);
    freopen("crystal.in","w",stdout);
    freopen("crystal.out","r",stdin);
    //freopen("crystal,in"."r".stdin);
    //freopen("crystal,out"."w".stdout);
瞪题半天居然想出来了：先按照站点存线路和到站厅的距离，然后用它算线路之间的边权，接着Floyd，最后回答
O(m*d^2+n^3+q*d^2)
  500000*20*20=200000000
  500*500*500 =125000000
  100000*20*20= 40000000
               365000000
不会写命令行，写了个先从.out读取再从.ans读取，结果.ans读不到，中间fclose也没用，请求上迷惑行为大赏让大佬们当一下事后诸葛亮

***居然卡常，气得我把vector全换成普通数组，再加个我会的最快快读，居然把六七（👇☝👇☝👇☝👇☝👇☝👇☝）卡过去了
*/

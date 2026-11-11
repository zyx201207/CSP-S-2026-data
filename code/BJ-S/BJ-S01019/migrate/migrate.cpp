//所以万圣节到底等不等于圣诞节？
#include <bits/stdc++.h>
using namespace std;
template<typename T>
void read(T &x){
    char ch;
    bool flag = false;
    while (!isdigit(ch = getchar_unlocked())) flag |= ch == '-';
    x = ch ^ 48;
    while (isdigit(ch = getchar_unlocked())) x = (x << 3) + (x << 1) + (ch ^ 48);
    if (flag) x = -x;
}
template<typename T>
void write(T x){
    if (x >= 10) write(x / 10);
    putchar_unlocked(x % 10 ^ 48);
}
long long a[2000005];
int dis[2000005],cnt[2000005];
int n;
long long d;
void bfs(int start){
    memset(dis,0x3f,sizeof dis);
    memset(cnt,0,sizeof cnt);
    queue<int>q;
    q.push(start);
    dis[start] = 0;
    cnt[start] = 1;
    while (!q.empty()){
        int now = q.front();
        q.pop();
        for (int i = 1;i <= n;i++){
            if (abs(a[now] - a[i]) <= d){
                if (dis[i] > dis[now] + 1){
                    dis[i] = dis[now] + 1;
                    cnt[i] = cnt[now];
                    q.push(i);
                }
                else if (dis[i] == dis[now] + 1) cnt[i] += cnt[now];
            }
        }/*
        for (int i = 1;i <= n;i++) cerr << dis[i] << " ";
        cerr << endl;*/
    }
}
void solve(){
    read(n);
    read(d);
    for (int i = 1;i <= n;i++) read(a[i]);
    long long ans = 0;
    for (int i = 1;i <= n;i++) {
        bfs(i);
        for (int j = 1;j <= n;j++) {
            ans += cnt[j] == 2;
            //cerr << cnt[j] << " ";
        }
        //cerr << endl;
    }
    write(ans / 2);
    putchar_unlocked(10);
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    read(c);
    read(t);
    while (t--) solve();
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
我最多能写个Tn^2。
预计得分100+92+40+0=232，T4连暴力都没啥欲望了。
*/

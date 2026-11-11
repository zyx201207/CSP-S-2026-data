
#include <bits/stdc++.h>
using namespace std;
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
struct edge{int y,next;}v[2000005];
int head[1000005],cnt;
void addedge(int x,int y){
    v[++cnt] = {y,head[x]};
    head[x] = cnt;
}
void solve(){
    cnt = -1;
    memset(head,-1,sizeof head);
    int n,k;
    read(n);
    read(k);
    for (int i = 1;i < n;i++){
        int x,y;
        read(x);
        read(y);
        addedge(x,y);
        addedge(y,x);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    read(c);
    read(t);
    while(t--) solve();
    return 0;
}
/*
现在是17:45。
T4不做了，因为连判断是否是连通块都不会，根本打不了暴力。
预估得分100+92+40+0=232,
回首来路，不由得百感交集。如果CSP-J没拿到一级证，那我可能就要AFO了。不过我的J预估能拿100+100+100+48=348。还很幸运。
为了OI，我付出了很多努力。成败就在此一举。
但我还是不够好。J4、S2拿不到满的我，怕是拿了S一级，上NOIP也不好做题。
虽然这段时间教练只给我们打基本是青蓝紫黑的NOIP模拟赛。只有时掺一道黄。我从来都是只能在那道黄上拿满分，剩下的暴力或乱搞。
我是luogu uid=857437，BJ-J01101。在此请求放上迷惑行为大赏。
现在是17:55。

现在是18:10。
第二题（subway）中的样例解释请忽略公式中的变量部分，以文字叙述部分与公式中的数值部分为准。
现在是18:11。

现在是18:19。
一个人机子出了问题，又给主任叫过来了。能听见主任说“有这句话就死机”。不知道这哥们写了啥。
现在是18:20。

现在是18:23。
闲的没事，手贱点了一下Code::Blocks的Start here页的图标，居然进了官网，吓得我赶紧趁它加载出来前把它关掉了。
现在是18:24。

现在是18:28。
打算卡最后一秒秒提交，结果发现系统时间快2s。
现在是18:29。

现在是交卷前一秒。
最后问一句，所以万圣节到底等不等于圣诞节？
*/

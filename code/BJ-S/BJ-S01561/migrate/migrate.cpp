#include<bits/stdc++.h>
using namespace std;
int land_x[1000000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    int c,t;
    cin>>c>>t;
    while( (t--) &&c){
        long long n,d;
        cin>>n>>d;
        for(int i=0;i<n;i++) cin>>land_x[i];
        cout<<"gun mu";

    }
	return 0;
}

/*
还剩下30钟，肯定作不完
思路：先根据输入建图（把可以互通的岛屿相连）
然后找出所有的强联通分量
排除所有含有奇数个节点的强连通分量
然后答案就是所有剩下的强连通分量的节点个数的一半

优化：忽略相联通的相邻岛屿

T1 OK
T2 ???
T3/T4 GUN MU

坏消息：这可能是我最后一次比赛了
好消息：我现在是学校信竞最老资历

其实为我最开始只是对编程感兴趣，后来在家长的影响下不知道怎么就打上竞赛了（


key:
freopen("migrate.in","r",stdout);
freopen("migrate.out","w",stdin);
freopen("migrate.in","w",stdout);
freopen("migrate.in","w",stdin);
freopen("migrate.in","r",stdout);
freopen("migrate.in","r",stdin);

migreta

#include<bits\stdc++.h>
int mian(){
whlie()

rp++
orz
oi
1145141919810

genshin impact(my uid:295849190)
luo gu
never give you up

因该会有人作大赏的时候发现我把（

*/

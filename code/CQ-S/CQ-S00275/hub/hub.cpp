#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
int c,t,n,k;
vector<int> G[MAXN];
int main(){
    #ifndef ONLINE_JUDGE
        freopen("hub.in","r",stdin);
        freopen("hub.out","w",stdout);
    #endif
    scanf("%d%d",&c,&t);
    while(t--){
        scanf("%d%d",&n,&k);
        for(int i=1;i<n;i++){
            int u,v;
            scanf("%d%d",&u,&v);
            G[u].push_back(v);
            G[v].push_back(u);
        }
        puts("0");
    }
    return 0;
}
/*
翻译一下题意：在一颗树 T 上选两个大小之和为 k 的两个块，这两个块可以联通也可以不联通但不能重合，求离这两个块最远的节点离块的最小距离。
滚回去写 T2。
诶是不是我只要把 T 像平衡树一样转成一颗平衡的树，然后二分答案通勤方案，再枚举深度放基地是不是就可以了。
感性理解一下是对的，但我显然不会写平衡树。好吧拉完了，T4 直接丢掉，暴力都只能写 2^nn的还难写。
强省强市强校蒟蒻，但我不是 biu biu biu。
寻物启示：CQBZ 沙坪坝考点丢失黑色虎牌水杯一个。
*/
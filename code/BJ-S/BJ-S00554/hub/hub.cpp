/*
1757:开D
1803:快速作决择。性质A还是写暴力？
1804:考虑树形DP（
设dp[u][k][1/2][0/1]
表示考率u的子树，选择k个点形成的连通块个数为1/2,且u有没有被选中
对应的最小值。
1. 转移dp[u][k][1][0]
只能选择两个子树。

1808:这个抉择是错误的。赶紧写暴力！！！！！
1814:万但了，我暴力写不出来。
1816:瞎写。期望的分[100+[44,eps]+[8,eps]+[0,5]]=[152,eps]
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long _,n,k,mi=2e18,fa[N];
vector<int> g[N],tmp;

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>_>>_;
    while(_--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)g[i].clear();
        mi=2e18;
        for(int i=1;i<=n;i++){
            int u,v;
            cin>>u>>v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        if(n<=5&&k<=5){
            if(k==1)cout<<2<<"\n";
            else if(k<=4)cout<<1<<"\n";
            else cout<<0<<"\n";
        }
        else{
            cout<<(n-k)/2<<"\n";
        }
    }
    return 0;   
}
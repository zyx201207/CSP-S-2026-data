#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,d,q;
ll w[500005];
ll k;
pair<ll,ll> a[500005][21];
ll dp[505][505];
unordered_map<ll,unordered_map<ll,ll>> mp;
int siz[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>n>>m>>d>>q;//第一个是测试点编号，输入没问题。
    memset(dp,0x3f,sizeof(dp));
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            int awa,qwq;
            cin>>awa>>qwq;
            mp[awa][i]=qwq;
            a[awa][++siz[awa]]={i,qwq};
        }
    }
    for(int i=1;i<=m;i++){
        for(int jx=1;jx<=siz[i];jx++){
            for(int kx=1;kx<=siz[i];kx++){
                auto j=a[i][jx];
                auto k=a[i][kx];
                if(j.first==k.first){
                    dp[j.first][j.first]=0;
                    continue;
                }
                dp[j.first][k.first]=min({dp[j.first][k.first],dp[k.first][j.first],j.second+k.second});
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x,y;
        ll ans;
        cin>>x>>y;
        ans=1e18;
        for(ll st1=1;st1<=siz[x];st1++){
            for(ll en1=1;en1<=siz[y];en1++){
                auto en=a[y][en1],st=a[x][st1];
                ans=min(ans,dp[st.first][en.first]+w[x]+w[y]+mp[x][st.first]+mp[y][en.first]);
            }
        }cout<<ans<<"\n";
    }
    return 0;
}
/*
15：00开始写T2

好题！
我想到了，用我们的Floyd大人！！！
首先，发现每个站最多被20条线经过，则考虑枚举起点和终点分别乘坐哪条线，直接用Floyd获得起点坐第x条线,终点坐第y条线的答案！！！

15：46分爆切T2！！！
我觉得7钩，有感觉吗？
*/
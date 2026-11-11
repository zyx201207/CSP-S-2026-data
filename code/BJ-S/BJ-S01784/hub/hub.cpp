#include<bits/stdc++.h>
using namespace std;
const int N=15;
int c,T,n,k,tdis;
vector<int>g[N];
bool flag[N];
int lowbit(int x){return x&-x;}
void dfs(int x){
    flag[x]=false;
    for(int it:g[x])if(flag[it])dfs(it);
}void ddfs(int prv,int x,int dis){
    if(flag[x]){
        tdis=min(tdis,dis);
        return;
    }for(int it:g[x])if(it!=prv)ddfs(x,it,dis+1);
}int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=0;i<n;++i)g[i].clear();
        for(int i=1;i<n;++i){
            int u,v;
            cin>>u>>v;
            --u,--v;
            g[u].push_back(v);
            g[v].push_back(u);
        }int ans=INT_MAX;
        for(int mask=0;mask<(1<<n);++mask){
            int cnt=0,tmp=mask;
            while(tmp){
                ++cnt;
                tmp-=lowbit(tmp);
            }if(cnt!=k)continue;
            for(int i=0;i<n;++i){
                if((mask>>i)&1)flag[i]=true;
                else flag[i]=false;
            }cnt=0;
            for(int i=0;i<n;++i)if(flag[i]){
                dfs(i);
                ++cnt;
            }if(cnt>2)continue;
            int now=0;
            for(int i=0;i<n;++i){
                if((mask>>i)&1)flag[i]=true;
                else flag[i]=false;
            }for(int i=0;i<n;++i)if(!flag[i]){
                tdis=INT_MAX;
                ddfs(-1,i,0);
                now+=tdis;
            }ans=min(ans,now);
        }cout<<ans<<'\n';
    }return 0;
}//g++ -O2 -Wall -Wextra d.cpp
//./a.out
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/
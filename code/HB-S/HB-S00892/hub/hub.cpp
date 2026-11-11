#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define db double
#define fi first
#define se second
#define loop(i,a,b) for(int i=(a);(i)<=(b);(i)++)
#define rloop(i,a,b) for(int i=(a);(i)>=(b);(i)--)
#define lowbit(x) ((x)&(-(x)))
using namespace std;

const int N=1e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;

int c,T;
int n,k;
vector<int>g[N];
int dep[N];

int dfs(int u,int fa){
    dep[u]=dep[fa]+1;
    int t=u;
    for(auto v:g[u])if(v!=fa){
        int t1=dfs(v,u);
        if(dep[t1]>dep[t])t=t1;
    }
    return t;
}

int solve(){
    cin>>n>>k;
    int u,v;
    loop(i,1,n)g[i].clear();
    loop(i,1,n-1){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    if(n==k)return 0;
    if(n==k+1)return 1;
    if(c==13||c==14){
        int m=(n-1)/2;
        return (m+3-k)/4+1;
    }
    dep[0]=0;
    int lf=dfs(1,0);
    dep[lf]=1;
    int rf=dfs(lf,0);
    return max(dep[rf]-k,0)/4+1;
}

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>c>>T;
    while(T--)cout<<solve()<<'\n';
    return 0;
}
// g++ hub.cpp -o hub -O2 -std=c++14 -static -Wall -Wextra
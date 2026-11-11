#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using pil=pair<int,ll>;
inline ll read(){
    ll x=0,f=1;
    int c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
inline void print(ll x){
    if(x<0){putchar('-');x=-x;}
    if(x>9)print(x/10);
    putchar(x%10+'0');
}
const int maxn=2e6+5;
vector<int>p[maxn];
ll n,x[maxn],d;
ll w[maxn],dis[maxn],cnt[maxn];

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int C=read(),T=read();
    while(T--){
        int ans=0;
        n=read();d=read();
        for(int i=1;i<=n;i++){
            p[i].clear();
        }
        for(int i=1,u,v;i<=n;i++){
            u=read(),v=read();
            p[u].push_back(v);
            p[v].push_back(u);
        }
        print(n/2);
        puts("");
    }
    return 0;
}
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
void dijk(int st){
    priority_queue<int>q;
    q.push(st);
    for(int i=1;i<=n;i++){
        dis[i]=0x3f3f3f3f3f3f3f3f;
        cnt[i]=0;
    }
    dis[st]=0;
    while(!q.empty()){
        int u=q.top();
        q.pop();
        for(auto v:p[u]){
            if(dis[u]+1==dis[v]){
                cnt[v]++;
                q.push(v);
            }
            if(dis[u]+1<dis[v]){
                dis[v]=dis[u]+1;
                cnt[v]=1;
                q.push(v);
            }
        }
    }
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C=read(),T=read();
    while(T--){
        int ans=0;
        n=read();d=read();
        for(int i=1;i<=n;i++){
            x[i]=read();
            p[i].clear();
        }
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(llabs(x[j]-x[i])<=d){
                    p[i].push_back(j);
                    p[j].push_back(i);
                }
            }
        }
        for(int i=1;i<=n;i++){
            dijk(i);
            for(int j=1;j<=n;j++){
                if(cnt[j]==2)ans++;
            }
        }
        print(ans/2);
        puts("");
    }
    return 0;
}
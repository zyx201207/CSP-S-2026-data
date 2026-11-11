#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5005,inf=1e18;
int h[N],to[N*N],nx[N*N],idx=1;
int du[N];
int tmp[N];
int dis[N],cnt[N];
int x[N];
int ans;
int n,d;

void add(int u,int v) {
    nx[idx]=h[u];
    to[idx]=v;
    h[u]=idx++;
    du[v]++;
}

int que[N],l,r;

void tp(int s) {
    l=1,r=0;
    for(int i=1;i<=n;i++) dis[i]=inf;
    for(int i=1;i<=n;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) tmp[i]=du[i];
    for(int u=1;u<s;u++) {
        tmp[u]=0;
        for(int i=h[u];i;i=nx[i]) {
            int v=to[i];
            tmp[v]--;
        }
    }
    dis[s]=0;
    que[++r]=s;
    cnt[s]=1;
    while(l<=r) {
        int u=que[l++];
        for(int i=h[u];i;i=nx[i]) {
            int v=to[i];
            if(dis[v]>dis[u]+1) {
                dis[v]=dis[u]+1;
                cnt[v]=cnt[u];
            }
            else if(dis[v]==dis[u]+1) {
                cnt[v]+=cnt[u];
            }
            tmp[v]--;
            if(!tmp[v]) que[++r]=v;
        }
    }
    for(int i=1;i<=n;i++) {
        if(cnt[i]==2) {
            ans++;
        }
    }
}

void sol() {
    cin>>n>>d;
    for(int i=1;i<=n;i++) du[i]=0;
    for(int i=1;i<=n;i++) h[i]=0;
    for(int i=1;i<=n;i++) cin>>x[i];
    for(int i=1;i<=n;i++) {
        for(int j=1;j<i;j++) {
            if(x[i]-x[j]<=d) {
                add(j,i);
            }
        }
    }
    ans=0;
    for(int i=1;i<=n;i++) tp(i);
    cout<<ans<<'\n';
}

signed main() {
    freopen("migrate.in","r",stdin),freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--) sol();
    return 0;
}
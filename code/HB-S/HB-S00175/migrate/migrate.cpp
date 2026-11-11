#include<bits/stdc++.h>
#define ll long long
#define db double
#define fi first
#define se second
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=2e6+5;
const int mod=1e9+7;
const int inf=0x3f3f3f3f;
int n,d;
ll x[N];
pair<ll,ll> a[N];
int far[N];
ll rd() {
    ll num=0,k=1,c=getchar();
    while(!isdigit(c)) {
        if(c=='-') k=-1;
        c=getchar();
    }
    while(isdigit(c)) {
        num=num*10ll+c-48ll;
        c=getchar();
    }
    return num*k;
}
bool cmp(pair<ll,ll> x,pair<ll,ll> y) {
    if(x.fi!=y.fi) return x.fi<y.fi;
    return x.se<y.se;
}
//boom force start
bool ok=1;
int cnt;
void dfs(int u,int dis,int goal,int lim) {
    if(ok=0||dis>lim) return;
    if(u==goal) {
        cnt++;
        if(cnt>2) ok=0;
        return;
    }
    for(int i=u+1;i<=far[u];i++) {
        dfs(i,dis+1,goal,lim);
    }
}
void solve() {
    n=rd(),d=rd();
    for(int i=1;i<=n;i++) {
        x[i]=rd();
        a[i]={x[i],x[i]+d};
    }
    for(int i=1;i<=n;i++) {
        far[i]=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
    }
    int ans=0;
    for(int i=1;i<=n;i++) {
        for(int j=i+1;j<=n;j++) {
            int dis=0,k=i;
            for(k=i+far[i];k<j;k+=far[k])dis++;
            ok=1;
            cnt=0;
            dfs(i,0,j,dis);
            if(cnt==2&&ok) ans++; 
        }
    }
    printf("%d\n",ans);
}
int main() {
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C=rd(),T=rd();
    while(T--) {
        solve();
    }
    return 0;
}


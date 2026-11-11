#include<bits/stdc++.h>
using namespace std;
const int N=500250;
long long  a[N],n,m,st,ans,dis[N];
void dfs(int u,int l) {
    st=m;
    if(u<=1||u>n) return;
    for(int i=u-1;i>=1;i--) {
        l++;
        st-=(a[u]-a[i]);
        if(st<0) {
            st+=(a[u]-a[i]);
            l--;
            break;
        }
    }
    int j;
    for(j=u+1;j<=n;j++) {
        if(a[j]==a[u]) l++;
        else break;
    }
    
    if(ans<l) ans=l;
    if(dis[u-1]==0) {
        dis[u-1]=1;
        dfs(u-1,1);
    }
    u=j-1;
    if(dis[u+1]==0) {
        dis[u+1]=1;
        dfs(u+1,1);
    }
    return;
}
long long cmp (long long x,long long y) {
    return x<y;
}
int main() {
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    int b=(n+1)/2;
    dis[b]=1;
    dfs(b,1);
    cout << ans <<endl;
    return 0;
}
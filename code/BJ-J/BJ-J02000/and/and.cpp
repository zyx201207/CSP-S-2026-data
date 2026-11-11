#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n,m,ans;
int a[N];
void dfs(int step, int cnt, int zhi){
    if(step==n){
        if(cnt!=m) return;
        ans=max(ans,zhi);
        return;
    }
    dfs(step+1,cnt+1,zhi&a[step+1]);
    dfs(step+1,cnt,zhi);
}
bool cmp(int a, int b){
    return a>b;
}
signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    if(n<20){
        int INF=pow(2,31);
        dfs(0,0,INF);
        cout<<ans;
    }else if(n<=20000 && m==1){
        int ans=-1;
        for(int i = 1; i <= n; i++) ans=max(ans,a[i]);
        cout<<ans;
    }else if(n<=20000 && n==m){
        int ans=a[1];
        for(int i = 2; i <= n; i++) ans&=a[i];
        cout<<ans;
    }else if(n<=5000 && m==2){
        int ans=-1;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n && j != i; j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
    }else{
        sort(a+1,a+n+1,cmp);
        int ans=1;
        for(int i = 2; i <= m; i++) ans&=a[i];
        cout<<ans;
    }
    return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;
int n,m,a[200004];
bool used[200004];
int dfs(int nowand,int nowxuan){
    if(nowxuan==m) return nowand;
    int ans=-1;
    for(int i=1;i<=n;++i){
        if(used[i]) continue;
        used[i]=1;
        ans=max(ans,dfs(nowand&a[i],nowxuan+1));
        used[i]=0;
    }return ans;
}
int main(){
    #if 01
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    #endif // freopen
    cin>>n>>m;for(int i=1;i<=n;++i) cin>>a[i];
    sort(a+1,a+n+1);
    if(m==1) {cout<<a[n];return 0;}
    if(m==2) {
        int ans=-1;
        for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j)
            if(ans<a[i]&a[j]) ans=a[i]&a[j];
        cout<<ans;return 0;
    }
    if(m==n) {
        int ans=a[1];for(int i=1;i<=n;++i) ans&=a[i];
        cout<<ans;return 0;
    }
    cout<<dfs(2147483647,0);
}

#include <bits/stdc++.h>
using namespace std;
int n,m;
long long ans;
long long a[200005];
void dfs(int x,long long cnt,int step){
    if(step==m){
        ans=max(ans,cnt);
        return;
    }
    if(x>n) return;
    dfs(x+1,cnt&a[x],step+1);
    dfs(x+1,cnt,step);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    if(m==1){
        for(int i=1;i<=n;i++) ans=max(ans,a[i]);
        cout << ans;
        return 0;
    }
    if(m==n){
        ans=a[1]&a[2];
        for(int i=3;i<=n;i++) ans&=a[i];
        cout << ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout << ans;
        return 0;
    }
    if(n<=20){
        for(int i=1;i<=n;i++) dfs(i+1,a[i],1);
        cout << ans;
        return 0;
    }
    sort(a+1,a+n+1,greater<long long>());
    ans=a[1];
    for(int i=2;i<=m;i++) ans&=a[i];
    cout << ans;
    return 0;
}

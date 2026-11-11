#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans,num[200005],x,v[200005],sum,mx,p[35],cnt[32];
void dfs(int k){
    if (num[k-1]<=max(ans,p[x])) return ;
    if (k>m){
        ans = num[m];
        return ;
    }
    for (int i=1; i<=n; i++){
        if (v[i]==0){
            v[i] = 1;
            num[k] = num[k-1]&a[i];
            dfs(k+1);
            v[i] = 0;
        }
    }
}
void f(int k){
    int y = a[k];
    for (int i=32; i>=0; i--){
        if (y>=p[i]){
            y -= p[i];
            cnt[i]++;
        }
        if (y<=0) break;
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    p[0] = 1;
    for (int i=1; i<=32; i++) p[i] = p[i-1]*2;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        f(i);
        if (i==1) sum=a[i];
        else sum = sum&a[i];
        mx = max(mx,a[i]);
    }
    if (n==m){
        cout << sum;
        return 0;
    }
    if (m==1){
        cout << mx;
        return 0;
    }
    x = -1;
    for (int i=32; i>=0; i--){
        if (cnt[i]>=m){
            x = i;
            break;
        }
    }
    if (x==-1){
        cout << 0;
        return 0;
    }
    for (int i=1; i<=n; i++){
        num[1] = a[i];
        v[i] = 1;
        dfs(2);
        v[i] = 0;
    }
    cout << ans;
    return 0;
}
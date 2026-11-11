#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+5;

int n,m,a[N];

map<int,int> vis;

namespace subtask1{
    int maxn=-1e18,path[N];
    
    void dfs(int dep,int cnt){
        if(cnt==m+1){
            int sum=path[1];
            for(int i=2;i<=m;i++) sum&=path[i];
            maxn=max(maxn,sum);
            return;
        }
        if(dep==n+1) return;

        dfs(dep+1,cnt);

        path[cnt]=a[dep];
        dfs(dep+1,cnt+1);
    }
    
    void solve(){
        dfs(1,1);
        cout << maxn << '\n';
    }
}

namespace subtask2{
    int maxn=-1e18;
    
    void solve(){
        for(int i=2;i<=n;i++){
            for(int j=1;j<i;j++) maxn=max(maxn,a[i]&a[j]);
        }
        cout << maxn << '\n';
    }
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];

    for(int i=0;i<=30;i++) vis[(1<<i)]=1;
    
    if(n<=20){
        subtask1::solve();
    }else if(m==1){
        int maxn=-1e18;
        for(int i=1;i<=n;i++) maxn=max(maxn,a[i]);
        cout << maxn << '\n';
    }else if(m==n){
        int ans=a[1];
        for(int i=2;i<=n;i++) ans&=a[i];
        cout << ans << '\n';
    }else if(m==2){
       subtask2::solve();
    }else if(m==n-1){
        sort(a+1,a+1+n,greater<int>());
        int maxi=-1e18;
        for(int i=n;i>=1;i--){
            if(vis[a[i]]){
                maxi=i;
                break;
            }
        }
        int ans=-1;
        if(maxi!=1) ans=a[1];
        else ans=a[2];
        for(int i=1;i<=n;i++){
            if(i!=maxi) ans&=a[i];
        }
        cout << ans << '\n';
    }
    else{
        sort(a+1,a+1+n,greater<int>());
        cout << a[m] << '\n';
    }
    return 0;
}
//g++ -o and and.cpp -O2 -std=c++14 -static
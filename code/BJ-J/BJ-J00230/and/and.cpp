#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2005;
int a[N];
int n,m;
int mx = 0;
void dfs(int i,int k,int ans){
    if(k == m){
        mx = max(mx,ans);
        return;
    }

    if(i == n + 1){
        return;
    }
    if(k != 0)
        dfs(i+1,k+1,ans & a[i]);
    else
        dfs(i+1,1,a[i]);
    dfs(i+1,k,ans);

}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    int mx2 = 0;
    int mx3 = 0;
    for(int i = 1;i <= n;i++){
            cin>>a[i];
            if(i == 1)
                mx3 = a[i];
            mx3 &= a[i];
            mx2 = max(mx2,a[i]);
    }
    if(m == 1){
        cout<<mx2;
        return 0;
    }
    if(m == n){
        cout<<mx3;
        return 0;
    }


    dfs(1,0,0);
    cout<<mx;
    return 0;
}

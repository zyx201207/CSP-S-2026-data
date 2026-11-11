#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+5;
int a[N],n,m,MAX;

void dfs(int node,int ans,int town){
    if(town == m){
        MAX = max(ans,MAX);
    }
    for(int i = node+1;i <= n;i++){
        if(town < m) dfs(i,ans & a[i],town + 1);
    }
}

bool cmp(int a,int b){
    return a > b;
}

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    if(n > 2000){
        sort(a+1,a+n+1,cmp);
        cout << (a[1] & a[2] & a[3]);
    }
    else{
        for(int i = 1;i <= n-m+1;i++) dfs(i,a[i],1);
        cout << MAX;
    }
}

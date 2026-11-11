
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 200005;
int n,a[N],m;
int dfs(int x,bool f,int cnt){
    if(cnt == m && f)
        return a[x];
    if(f)
        return max(dfs(x+1,0,cnt)&a[x],dfs(x+1,1,cnt+1)&a[x]);
    else
        return max(dfs(x+1,0,cnt),dfs(x+1,1,cnt+1));
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cout<<max(dfs(1,0,0),dfs(1,1,1));
    return 0;
}

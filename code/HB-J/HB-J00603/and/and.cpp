#include<bits/stdc++.h>
using namespace std;
long long a[100050],vis[100050];
long long n,m,mx=-100;
long long dfs(int step,long long x){
    if(step==m)
    {
        mx=max(mx,x);
        return x;
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==0&&step<m){
            vis[i]=1;
            dfs(step+1,a[i]&x);
            vis[i]=0;
        }
    }
    return x;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    for(int k=1;k<=n;k++){
        vis[k]=1;
        dfs(1,a[k]);
        vis[k]=0;
    }
    cout<<mx;
    return 0;
}

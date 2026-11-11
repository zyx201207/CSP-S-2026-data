#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[1000000],vis[1000000],sum;
void dfs(long long x,long long y,long long ans){
    if(y==0){
        sum=max(sum,ans);
        return;
    }
    for(long long i=x;i<=n;i++){
            if(vis[i]==0){
                    vis[i]=1;
                    y--;
        if(ans==0){
        dfs(i,y,a[i]);
        }else{
        dfs(i,y,ans&a[i]);
        }
        y++;
        vis[i]=0;
            }

    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    dfs(1,m,0);
    cout<<sum;
    return 0;
}

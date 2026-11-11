#include<bits/stdc++.h>
using namespace std;
long long n,m,ans=-1;
long long a[200001];
void dfs(long long x,long long cnt,long long sum){
    if(x>n){
        if(cnt==m){
            ans=max(ans,sum);
        }
        return;
    }
    if(cnt<m){
        dfs(x+1,cnt,sum);
        dfs(x+1,cnt+1,sum&a[x]);
    }else{
        dfs(n+1,cnt,sum);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        long long sum=-1;
        for(long long i=1;i<=n;i++){
            sum&=a[i];
        }
        cout<<sum;
        return 0;
    }
    if(m==2){
        long long ans=-1;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        long long maxx=-1;
        for(int i=1;i<=n;i++){
            maxx=max(maxx,a[i]);
        }
        cout<<maxx;
        return 0;
    }
    dfs(1,0,-1);
    cout<<ans;
    return 0;
}

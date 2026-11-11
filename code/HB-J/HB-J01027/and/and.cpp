#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005],n,m,ans=0;
void dfs(int x,int now){
    if(now==m){ans=max(ans,x);return;}
    for(int i=x+1;x<n-m+2;i++){
        dfs(a[x]&a[i],now+1);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        for(int i=1;i<n;i++){
            ans+=a[i]&a[i+1];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        for(int i=1;i<n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<n;i++){
            ans=max(ans,a[i]&a[i+1]);
        }
        cout<<ans;
        return 0;
    }
    dfs(1,1);
    return 0;
}

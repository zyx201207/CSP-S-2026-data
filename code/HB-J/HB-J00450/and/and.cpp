#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[300100],ans,b[300100],c[300100];
void dfs(int x,int y,int q){
    if(x>m){
        ans=max(ans,y);
        return;
    }
    if(y<=ans){
        return;
    }
    for(int i=q;i<=n;i++){
        dfs(x+1,y&a[i],i+1);
    }
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(m==n){
        ans=a[1];
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }
    if(m==1){
        for(int i=1;i<=n;i++){
            ans=max(ans,a[i]);
        }
        cout<<ans;
        return 0;
    }
    if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ans=max(ans,a[i]&a[j]);
            }
        }
        cout<<ans;
        return 0;
    }
    if(m==n-1){
        b[0]=2147483647;
        for(int i=1;i<=n;i++){
            b[i]=a[i]&b[i-1];
        }
        c[n+1]=2147483647;
        for(int i=n;i>=1;i--){
            c[i]=a[i]&c[i+1];
        }
        for(int i=1;i<=n;i++){
            ans=max(ans,b[i-1]&c[i+1]);
        }
        cout<<ans;
        return 0;
    }
    if(n<=20){
        dfs(1,2147483647,1);
        cout<<ans;
        return 0;
    }
    cout<<0;
    return 0;
}

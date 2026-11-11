#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500010],b[500010],c[500010],m,ans=0;
void dfs(int x){
    for(int i=1;i<=x;i++){
        for(int j=1;i<=i;j++){
            ans++;
        }
    }
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        c[i]=a[i]*i;
        ll u=c[i]-b[i];
        if(u<=m){
            dfs(i);
        }
    }
    cout<<ans;
    return 0;
}

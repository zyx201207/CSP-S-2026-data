#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005];
int dfs(int i,int t,int k){
    if(t<=0)return k;
    int mx=0;
    for(int j=i+1;j<=n;j++){
        mx=max(mx,dfs(j,t-1,(k&a[j])));
    }
    return mx;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,dfs(i,m-1,a[i]));
        }
        cout<<mx;
    }else if(m==1){
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
    }else if(m==n){
        int u=a[1];
        for(int i=2;i<=n;i++){
            u&=a[i];
        }
        cout<<u;
    }
    else{
        cout<<0;
    }
    return 0;
}

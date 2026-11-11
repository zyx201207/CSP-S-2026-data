#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200020];
int maxn=-1;
void dfs(int cnt,int ans,int p){
    if(cnt==m){
        maxn=max(ans,maxn);
        return;
    }
    for(int i=p+1;i<=n+1;i++)
        dfs(cnt+1,ans&a[p],i);
}
bool cmp(int x,int y){
    return x>y;
}
int fun(int maxn){
    int cnt=1;
    for(int i=1;i<=30;i++){
        cnt*=2;
        if(cnt>maxn)
            return i-1;
    }
    return 30;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    if(n<=2000){
        for(int i=1;i<=n;i++)
            dfs(0,2147483647,i);
        cout<<maxn;
    }
    else{
        int maxn=-1;
        for(int i=1;i<=n;i++)
            maxn=max(a[i],maxn);
        int z=fun(maxn);
        int ans=pow(2,z)+pow(2,z-1);
        if(ans>maxn)
            cout<<pow(2,z)-1;
        else
            cout<<ans;
    }

    return 0;
}

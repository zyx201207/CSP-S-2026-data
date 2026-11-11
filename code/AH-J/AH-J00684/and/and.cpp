#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005],mx,dp[200005],sum;
int dfs(int x,int cnt){
    if(x==n+1){
        return (1<<x)-1;
    }
    int res=0;
    res=max(res,dfs(x+1,cnt+1)&a[x]);
    int w=dfs(x+1,cnt);
    if(w!=(1<<n+1)-1)res=max(res,w);
    return res;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==1)sum=a[i];
        else sum&=a[i];
        mx=max(mx,a[i]);
    }
    if(n<=20){cout<<dfs(1,0);return 0;}
    if(m==1){cout<<mx;return 0;}
    if(m==n){cout<<sum;return 0;}
    if(m==2){
        mx=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                mx=max(mx,a[i]&a[j]);
            }
        }
        cout<<mx;
        return 0;
    }
    cout<<0;
    return 0;
}

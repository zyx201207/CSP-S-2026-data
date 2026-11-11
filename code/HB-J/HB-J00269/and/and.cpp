#include <bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N];
int n,m;
long long mx=0;
void dfs(int now,long long sum,int num){
    if(now>n){
       if(num==m){
        mx=max(mx,sum);
       }
       return ;
    }
    dfs(now+1,(sum&a[now]),num+1);
    dfs(now+1,sum,num);
    return ;
}
void solve1(){
    dfs(1,1LL*(2<<30)-1,0);
    cout<<mx;
    return ;
}
void solve2(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,a[i]);
    }
    cout<<ans;
}
void solve3(){
    long long sum=1LL*(2<<30)-1;
    for(int i=1;i<=n;i++){
        sum=(sum&a[i]);
    }
    cout<<sum;
}
void solve4(){
    long long ans=0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,(a[i]&a[j]));
        }
    }
    cout<<ans;
}
long long pre[N],suf[N];
void solve5(){
    pre[1]=a[1];
    suf[n]=a[n];
    for(int i=2;i<=n;i++){
        pre[i]=(pre[i-1]&a[i]);
    }
    for(int i=n-1;i>=1;i--){
        suf[i]=(suf[i+1]&a[i]);
    }
    long long ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,(pre[i-1]&suf[i+1]));
    }
    cout<<ans;
}
void solve6(){
    sort(a+1,a+1+n);
    long long ans=0;
    for(int i=1;i<=m;i++){
        ans=(ans&a[i]);
    }
    cout<<ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        solve1();
    }else if(m==1){
        solve2();
    }else if(m==n){
        solve3();
    }else if(m==2){
        solve4();
    }else if(m==n-1){
        solve5();
    }else{
        solve6();
    }
    return 0;
}

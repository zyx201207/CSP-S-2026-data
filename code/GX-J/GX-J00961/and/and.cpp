#include <bits/stdc++.h>

#define c(x) cout<<x<<endl
#define inf 0x3f3f3f3f
#define fet(x) const int fet=x;

using namespace std;

fet(2e5+10);
int n,m,a[fet];
int ans=-inf;

bool vis[fet]={};
void dfs();
void solve1();

void solve2();

int s[fet];
void solve3();

signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(n<=20) solve1(); else
    if(n<=2000) solve2(); else
    if(n>2000)  solve3();
    return 0;
}

void solve3(){
    if(m==1){
        for(int i=1;i<=n;i++)
            ans=max(a[i],ans);
    }else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j) continue;
                else ans=max(ans,a[i]&a[j]);
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[i];
    }else if(m==n-1){
        s[1]=a[1];
        for(int i=2;i<=n;i++){
            s[i]=s[i-1]&a[i];
        }
        for(int i=2;i<=n;i++){
            ans=max(ans,s[i-1]|s[n]);
        }
    }
    c(ans);
}

void solve2(){
    if(m==1){
        for(int i=1;i<=n;i++)
            ans=max(a[i],ans);
    }else if(m==2){
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i==j) continue;
                else ans=max(ans,a[i]&a[j]);
    }else if(m==n){
        ans=a[1];
        for(int i=2;i<=n;i++)
            ans=ans&a[i];
    }else{
        sort(a+1,a+1+n);
        ans=a[n];
        for(int i=1;i<=m;i++)
            ans=ans&a[n-i];
    }
    c(ans);
}

void dfs(int dep,int sum){
    if(dep==m){
        ans=max(ans,sum);
        return;
    }
    if(dep==0){
        for(int i=1;i<=n;i++){
            vis[i]=true;
            dfs(dep+1,a[i]);
            vis[i]=false;
        }
    }else{
        for(int i=1;i<=n;i++){
            if(vis[i]) continue;
            vis[i]=true;
            dfs(dep+1,sum&a[i]);
            vis[i]=false;
        }
    }
}
void solve1(){
    dfs(0,0);
    cout<<ans;
}

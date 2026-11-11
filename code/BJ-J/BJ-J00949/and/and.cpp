#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
ll a[200100];
bool flag=true;
bool cmp(ll a,ll b){
    return a>b;
}
ll ans;
void dfs(int u,int cnt,ll sum){
    if(u>n){
        if(cnt==m){
            ans=max(ans,sum);
        }
        return;
    }
    if(cnt>m)return;
    dfs(u+1,cnt+1,sum&a[u]);
    dfs(u+1,cnt,sum);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(log2(a[i]+1)!=(int)log2(a[i]+1))flag=false;
    }
    if(m==1){
        ll maxn=0;
        for(int i=1;i<=n;i++){
            maxn=max(maxn,a[i]);
        }
        cout<<maxn;
        return 0;
    }else if(m==2){
        ll maxn=0;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                ll res=a[i]&a[j];
                maxn=max(maxn,res);
            }
        }
        cout<<maxn;
        return 0;
    }else if(flag){
        sort(a+1,a+n+1,cmp);
        cout<<a[m];
        return 0;
    }else if(m==n){
        ll ans=1;
        for(int i=1;i<=n;i++){
            ans&=a[i];
        }
        cout<<ans;
        return 0;
    }else{
        dfs(1,0,0);
        cout<<ans;
        return 0;
    }
    return 0;
}
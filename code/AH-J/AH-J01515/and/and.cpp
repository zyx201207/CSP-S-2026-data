#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[200005],ans;
void dfs(ll t,ll choose,ll tmp){
    if(choose>m) return;
    if(t>n){
        if(choose==m){
            ans=max(ans,tmp);
        }
        return ;
    }
    if(choose==0){
        dfs(t+1,choose+1,a[t]);
        dfs(t+1,choose,tmp);
    } else{
        dfs(t+1,choose+1,tmp&a[t]);
        dfs(t+1,choose,tmp);
    }
}
bool check(){
    for(int i=1;i<=n;i++){
        bool flag=false;
        for(int m=0;m<=30;m++){
            if((1<<m)-1==a[i]){
                flag=true;
            }
        }
        if(!flag) return false;
    }
    return true;
}
bool check2(){
    for(int i=1;i<=n;i++){
        if(a[i]>=4) return false;
    }
    return true;
}
bool check3(){
    for(int i=1;i<=n;i++){
        if(a[i]!=i-1) return false;
    }
    return true;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    if(m==1){
        ll mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,a[i]);
        }
        cout<<mx;
        return 0;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            ans&=a[i];
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
    if(check()||check2()){
        cout<<a[n-m+1];
        return 0;
    }
    if(check3()){
        cout<<n-m;
        return 0;
    }
    if(m==n-1){
        for(int i=1;i<=n;i++){
            ll tmp;
            for(int j=1;j<=n;i++){
                if(j!=i) tmp&=a[j];
                else if(j==1&&i!=1||j==2&&i==1) tmp=a[j];
            }
            ans=max(ans,tmp);
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0);
    cout<<ans;
    return 0;
}

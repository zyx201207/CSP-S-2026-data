#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
int a[MAXN];
int ans=INT_MIN;
int n,m;
int bans;
int getb(int x){
    int r=0;
    for(;;){
        x/=2;
        r++;
        if(x==0)break;
    }
    return r;
}
void dfs(int index,int chosed,int now){
    now = now & a[index];
    if(chosed == m){
        if(now>ans){
            ans=now;
            bans=getb(ans);
        }
        return;
    }
    if(getb(now)<bans)return;
    if(n-index<m-chosed)return;
    for(int i=index+1;i<n;i++){
        dfs(i,chosed+1,now);
    }
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        if(m==1)ans=max(ans,a[i]);
        if(m==n){
            if(i==0)ans=a[i];
            else ans = ans & a[i];
        }
    }
    if(m==1||m==n){
        cout<<ans;
        return 0;
    }
    for(int i=0;i<n-m;i++){
        dfs(i,1,a[i]);
    }
    cout<<ans;
    return 0;
}
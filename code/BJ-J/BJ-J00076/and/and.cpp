#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN=2e5+5;
int n,m;
long long a[MAXN];
long long vis[MAXN];
void subtask1(){
    sort(a+1,a+1+n);
    cout<<a[n-m+1]<<endl;
    return ;
}
void subtask2(){
    ll ans=a[n-m+1];
    for(int i=n-m+1+1;i<=n;i++){
        ans=ans&a[i];
    }
    cout<<ans<<endl;
    return ;
}
ll mxx;
void dfs(int u,int l,ll ans){
    if(l==0){
        mxx=max(mxx,ans);
        return;
    }
    vis[u]=1;
    for(int i=1;i<=n;i++){
        if(vis[i]==0){
            vis[i]=1;
        dfs(i,l-1,(ans&a[i]));
        vis[i]=0;
        }
    }
}
void task(){
    for(int i=1;i<=n;i++){
        vis[i]=1;
        dfs(i,m-1,a[i]);
        vis[i]=0;
    }
    cout<<mxx<<endl;
    return;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    bool check1=true;
    bool check2=true;
    int nn=n;
    while(nn>1){
        if(nn%2!=0){
            check2=false;
            break;
        }
        nn=nn/2;
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
        long long l=a[i]+1;
        while(l>1){
            if(l%2!=0){
                check1=false;
                break;
            }
            l=l/2;
        }
        if(a[i]!=(i-1)){
            check2=false;
        }
    }
    if(n==1){
        cout<<a[1];
        return 0;
    }
    if(m==1){
        long long mx=0;
        for(int i=1;i<=n;i++){
            mx=max(a[i],mx);
        }
        cout<<mx;
        return 0;
    }
    if(n==m){
        ll mmx=a[1]&a[2];
        for(int i=3;i<=n;i++){
            mmx=mmx&a[i];
        }
        cout<<mmx<<endl;
        return 0;
    }
    if(check1){
        subtask1();
    }
    else{
        if(check2){
            subtask2();
        }
        else{
            task();
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m;
long long mt;
long long a[200010];
bool vis[200010];
void dfs(long long k,long long t,long long l){
    if(k==m){
        mt=max(mt,t);
    }else{
        for(int i=l+1;i<=n;i++){
            if(!vis[i]){
                vis[i]=1;
                if(t==-1) dfs(k+1,a[i],i);
                else dfs(k+1,t&a[i],i);
                vis[i]=0;
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
        long long t=a[1];
        for(int i=2;i<=n;i++){
            t&=a[i];
        }
        cout<<t;
    }else if(m==1){
        long long t=0;
        for(int i=1;i<=n;i++){
            t=max(t,a[i]);
        }
        cout<<t;
    }else{
        dfs(0,-1,0);
        cout<<mt;
    }
    return 0;
}

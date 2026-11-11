#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int n,m,mx,ans,x,a[N];
bool vis[N];
void dfs(int x){
    if(x>=n){
        int c=0,tmp,id;
        for(int i=1;i<=n;i++)
            c+=vis[i];
        if(c==m){
            for(int i=1;i<=n;i++)
                if(vis[i]){
                    tmp=a[i],id=i;
                    break;
                }
            for(int i=id+1;i<=n;i++)
                if(vis[i])
                    tmp&=a[i];
            ans=max(ans,tmp);
        }
        return;
    }
    vis[x]=1;
    dfs(x+1);
    vis[x]=0;
    dfs(x+1);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i],x&=a[i],mx=max(mx,a[i]);
    if(m==1){
        cout<<mx<<'\n';
        return 0;
    }
    else if(m==n){
        cout<<x<<'\n';
        return 0;
    }
    else if(m==2){
        mx=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if(i!=j)
                    mx=max(mx,a[i]&a[j]);
        cout<<mx<<'\n';
        return 0;
    }
    else{
        dfs(1);
        cout<<ans<<'\n';
    }
    return 0;
}
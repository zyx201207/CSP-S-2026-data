#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[N],ans[M],q[N],vis[M],cnt;
bool A=true;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<a[i-1]) A=false;
        if(a[i]!=a[i-1]) b[++cnt]=a[i];
    }
    if(m<=2){
        if(m==1){cout<<n;return 0;}
        for(int i=1;i<=n;i++){
            if(a[i]==a[n]) ans[a[n]]++;
            else ans[1]++,ans[2]++;
        }
        cout<<ans[1]<<" "<<ans[2];
    }
    else if(A){
        for(int i=1;i<=n;i++) ans[a[i]]=i;
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }
    else if(cnt<=10000){
        for(int i=1;i<=cnt;i++){
            int hh=i,tt=i-1;
            memset(vis,0,sizeof(vis));
            for(int j=i;j<=cnt;j++){
                if(vis[b[j]]<=tt&&vis[b[j]]) tt=vis[b[j]]-1;
                q[++tt]=b[j];vis[b[j]]=tt;
            }
            for(int j=hh;j<=tt;j++) ans[q[j]]++;
        }
        for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
    }
    else{
        int k=m-n%m;
        if(n%m==0) for(int i=1;i<=m;i++) cout<<n/m<<" ";
        else for(int i=1;i<=m;i++) if(i<=n%m) cout<<n/m+1+k<<" "; else cout<<n/m;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],sum[200005],mx,maxn;
void dfs(int idx,int cnt,int num){
    if(cnt==m){
        maxn=max(maxn,num);
        return ;
    }
    if(idx==n+1) return ;
    dfs(idx+1,cnt+1,num&a[idx]);
    dfs(idx+1,cnt,num);
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    sum[0]=0x3f3f3f3f;
    cin>>n>>m;
    //cout<<sum[0]<<endl;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]&a[i];
        mx=max(mx,a[i]);
    }
    if(m==1) cout<<mx;
    else if(m==n) cout<<sum[n];
    else if(m==2){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++) maxn=max(maxn,a[i]&a[j]);
        }
        cout<<maxn;
    }else if(m==n-1){
        for(int i=1;i<=n;i++){
            int vis[n+1]={0};
            vis[i+1]=max(sum[i+1],a[i+1]);
            for(int j=i+1;j<n;j++) vis[j+1]=vis[j]&a[j+1];
            maxn=max(maxn,sum[i-1]&vis[n]);
        }
        cout<<maxn;
    }else{
        dfs(1,0,0x3f3f3f3f);
        cout<<maxn;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500022];
int ans=0;
int maxx=-1e18;
void dfs(int k,int num,int idx,int isx){
    if(k>m)return;
    if(k==m&&num<=n&&idx<=n&&isx<=maxx){
        ans=max(ans,num);
        return;
    }
    for(int i=1;i<=n-idx;i++)if(k+abs(a[idx+i]-isx)<=m&&isx<=maxx&&num+1<=n&&idx+i<=n)dfs(k+abs(a[idx+i]-isx),num+1,idx+i,isx);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){cin>>a[i];maxx=max(a[i],maxx);}
    for(int i=1;i<=maxx;i++){
        dfs(0,0,0,i);
    }
    cout<<ans<<"\n";
    return 0;
}

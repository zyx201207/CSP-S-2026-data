#include<bits/stdc++.h>
using namespace std;
const int N_e3=2e3+12;
int f[N_e3][N_e3],n,m,a[N_e3],ans;
void dfs(int id,int k,int sum){
    if(id==n+1&&k!=m) return;
    if(k==m){
        ans=max(sum,ans);
        return;
    }
    dfs(id+1,k+1,(k==0?a[id]:a[id]&sum));
    dfs(id+1,k,sum);
}
//4 2 3 15 12 12
//5 3 31 3 1 15 7
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n-1){
        for(int i=1;i<=n;i++){
            int d=0;
            for(int j=1;j<=n;j++){
                if(j!=i){
                    d=(d==0?a[j]:d&a[j]);
                }
            }
            ans=max(ans,d);
        }
        cout<<ans;
        return 0;
    }
    dfs(1,0,0);
    //for(int i=1;i<=n;i++){
    //    int v=a[i],w=1;
    //    for(int j=m;j>=w;j--){
    //        if(j>=w)f[i]=max(f[i],f[i-w]&v);
    //    }
    //}
    //cout<<f[n];
    cout<<ans;
    return 0;
}

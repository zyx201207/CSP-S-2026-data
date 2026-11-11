#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[200010],f[200010];
void dfs(int x,int num){
    if(x>n){
        if(num!=m){
            return;
        }
        int res=0;
        for(int i=1;i<=n;i++){
            if(f[i]){
                if(!res){
                    res=a[i];
                }else{
                  res&=a[i];
                }
            }
        }
        ans=max(ans,res);
        return;
    }
    f[x]=1;
    dfs(x+1,num+1);
    f[x]=0;
    dfs(x+1,num);
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    if(n<=20){
        dfs(1,0);
        cout<<ans;
    }else{
        for(int i=1;i<=n;i++){
            if(!ans){
                ans=a[i];
            }else{
                ans&=a[i];
            }
        }
        cout<<ans;
    }
    return 0;
}

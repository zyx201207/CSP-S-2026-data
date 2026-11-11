#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,res,ans[500010],a[500010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        res++;
        if(a[i]==a[i-1]){
            ans[i-1]=ans[i]=res;
        }
    }
    for(int i=1;i<=m;i++){
        if(!ans[i]){
            cout<<res<<" ";
        }else{
            cout<<ans[i]<<" ";
        }
    }
    return 0;
}

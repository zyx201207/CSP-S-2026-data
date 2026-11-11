#include<bits/stdc++.h>
#define int long long
using namespace std;
int QQQ,T,a[2000005],n,d,res;
int dfs(int k,int r,int last){
    int ans=0;
    if(last>r) return 0;
    if(k==1){
        if(last==r) return 1;
        return 0;
    }
    for(int i=last+1;i<=n;i++){
        if(a[last]+d<a[i]) break;
        res++;
        ans+=dfs(k-1,r,i);
        res--;
    }
    return ans;
}
bool check(int l,int r){
    int cnt=0,len=1;
    int i=l;
    while(i<r){
        if(a[i+1]-a[i]>d) return 0;
        i=upper_bound(a+1,a+n+1,a[i]+d)-a-1;
        len++;
    }
    int ans=dfs(len,r,l);
    if(ans==2) return 1;
    return 0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>QQQ>>T;
    while(T--){
        cin>>n>>d;
        int ans=0;
        for(int i=1;i<=n;i++) cin>>a[i];
        for(int i=1;i<=n;i++){
            for(int j=i+3;j<=n;j++){
                if(check(i,j)) ans++;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define int long long
int s[500001],a[500001],n,m;
bool f(int mid,int k){
    return (((mid-1)*a[k]-s[k-1]+s[k-mid])<=m);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    stable_sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
    int l=1,r=n,ans=0;
    for(int i=1;i<=n;i++){
        l=1;
        r=i+1;
        while(l<r){
            int mid=l+r>>1;
            if(f(mid,i)){
                ans=max(ans,mid);
                l=mid+1;
            }
            else{
                r=mid;
            }
        }
        
    }
    cout<<ans;
    //15:54AC
}
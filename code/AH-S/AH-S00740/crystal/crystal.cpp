#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[500010];
int sum[500010];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=1;
    while(l<=r&&r<n){
        if((r-l+1)*a[r+1]-(sum[r]-sum[l-1])<=m){
            ans=max(ans,r-l+2);
            r++;
        }else{
            if(l==r)r++;
            l++;
        }
    }
    cout<<ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005],d[500005],sd[500005],s[500005],pre[500005];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){

        d[i]=a[i]-a[i-1];
        if(i==1) d[i]=0;
        sd[i]=sd[i-1]+d[i];
        s[i]=s[i-1]+sd[i];
        pre[i]=i*sd[i]-s[i];
    }
    //pre[j]-(i-1)*sd[j]+s[i-1];
    int l=0,r=n;
    int ans=0;
    while(l<=r){
        int mid=l+(r-l)/2;
        int f=0;
        for(int i=1;i<=n-mid+1;i++){
            int j=i+mid-1;
            if(pre[j]-(i-1)*sd[j]+s[i-1]<=m){
                f=1;
                break;
            }
        }
        if(f==1){
            ans=max(mid,ans);
            l=mid+1;
        }else{
            r=mid-1;
        }
    }
    cout<<ans;
}
//16:19 ac??????

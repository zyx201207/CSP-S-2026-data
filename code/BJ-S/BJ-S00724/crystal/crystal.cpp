#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans,a[500010],d[500010],s[500010],ss[500010];
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<n;i++){
        d[i]=a[i+1]-a[i];
    }
    for(int i=1;i<n;i++){
        s[i]=s[i-1]+d[i];
    }
    for(int i=1;i<n;i++){
        ss[i]=ss[i-1]+s[i];
    }
    for(int i=1;i<n;i++){
        int l=i,r=n-1,res;
        while(l<=r){
            int mid=(l+r)/2;
            int c=s[mid]*(mid-i+1)-(ss[mid-1]-ss[max(0ll,i-2)]);
            if(c<=m){
                res=mid;
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,res-i+1);
    }
    cout<<ans+1;
    return 0;
}

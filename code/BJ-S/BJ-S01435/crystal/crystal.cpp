#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500100],d[500100],l,r,mid,s,ans;
bool check(int x,int p){
    return (p-x+1)*a[x]-(d[p]-d[x-1])<=m;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    reverse(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        d[i]=d[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        l=i;
        r=n;
        while(l<=r){
            mid=(l+r)/2;
            if(check(i,mid)){
                l=mid+1;
                s=max(s,mid-i+1);
            }else{
                r=mid-1;
            }
        }
        ans=max(ans,s);
    }
    cout<<ans;
    return 0;
}

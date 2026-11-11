#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[200005],ans=-1e9;
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int l=1,r=l+1,ll=0,rr=0;
    while(l<=n){
        while(r<=n){
            if(a[l]&a[r]>ans){
                ans=a[l]&a[r];
                ll=l;
                rr=r;
            }
            r++;
        }
        l++;
        r=l+1;
    }
    a[ll]=0;
    a[rr]=0;
    for(int i=1;i<=m-2;i++){
        l=1,ll=0;
        int ans1=-1e9;
        while(l<=n){
            if(a[l]&ans>ans1){
                ans1=a[l]&ans;
                ll=l;
            }
            l++;
        }
        ans=ans1;
        a[ll]=0;
    }
    cout<<ans;
    return 0;
}

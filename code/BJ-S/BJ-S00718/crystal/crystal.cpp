#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int n,m,a[N],ans,p[N];
int tal(int l,int r){
    return a[r]*(r-l+1)-(p[r]-p[l-1]);
}
bool ok(int k){
    for(int i=1;i<=n-k+1;i++){
        if(tal(i,i+k-1)<=m){
            return 1;
        }
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        p[i]=a[i]+p[i-1];
    }
    p[n+1]=1e18+1;
    int l=0,r=n;
    while(l<r){
        int mid=(l+r)>>1;
        if(!ok(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
    }
    cout<<l-1;
    return 0;
}

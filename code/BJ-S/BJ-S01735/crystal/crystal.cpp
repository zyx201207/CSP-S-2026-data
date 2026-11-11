#include<bits/stdc++.h>
using namespace std;
const int N=500005;
int n,m,a[N],l,r,ans;
int f(int k){
    int res=0;
    for(int i=1;i<k;i++){
        res+=a[k]-a[i];
    }
    return res;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    l=1;r=n;
    while(l<r){
        int mid=(l+r+1)>>1;
        if(f(mid)>m) r=mid-1;
        else l=mid;
    }
    cout<<l;
    return 0;
}

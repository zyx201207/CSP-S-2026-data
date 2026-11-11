#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ans[500005];
bool ck(long long x){
    for(int i=x;i<=n;i++){
        long long sum=ans[i]-ans[i-x]-(a[i]-a[i-x])*(i-x);
        if(sum<=m)return true;
    }
    return false;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        ans[i]=ans[i-1]+(a[i]-a[i-1])*(i-1);
    }
    long long l=0,r=1e9,b;
    while(l<=r){
        long long mid=(l+r)/2;
        if(ck(mid)){
            l=mid+1;
            b=mid;
        }
        else r=mid-1;
    }
    cout<<b;
    return 0;
}

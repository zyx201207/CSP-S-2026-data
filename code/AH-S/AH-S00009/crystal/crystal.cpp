#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
int a[500005],sum[500005];
bool check(int mid,int n,int m){
    int l=1,r=mid;
    while(r<=n){
        int p=(r-l)*a[r]-(sum[r-1]-sum[l-1]);
        if(p<=m)return 1;
        l++,r++;
    }
    return 0;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid,n,m))l=mid;
        else r=mid-1;
    }
    cout<<l;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

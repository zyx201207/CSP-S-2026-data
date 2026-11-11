#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],pre[500005],ans;
bool check(int l,int r){
    long long sum=pre[l]-pre[r+1];
    long long x=a[r]*(r-l+1);
    return m>=x-sum;
}
long long work(int x){
    int l=1,r=x,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid,x)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    return x-r+1;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n);
    for(int i=n;i>=1;i--){
        pre[i]=pre[i+1]+a[i];
    }
    for(int i=n;i>=1;i--){
        ans=max(ans,work(i));
    }
    cout<<ans<<'\n';
    return 0;
}
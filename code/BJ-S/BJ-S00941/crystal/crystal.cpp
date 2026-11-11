#include<bits/stdc++.h>
using namespace std;
long long a[500100];
long long pre[500100];
long long n,m;
long long check(long long x,long long y){
    long long now=(y-x+1)*a[y]-pre[y]+pre[x-1];
    return now;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        pre[i]=a[i]+pre[i-1];
    }
    long long ans=0;
    long long r=1;
    long long l=1;
    while(r<=n&&l<=r){
        if(check(l,r)<=m){
            ans=max(ans,r-l+1);
            r++;
        }
        else if(check(l,r)>m){
            l++;
        }
    }
    cout<<ans;
    return 0;
}

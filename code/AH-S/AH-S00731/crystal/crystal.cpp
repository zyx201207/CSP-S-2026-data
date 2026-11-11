#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,s[500005],ans;
bool mycheck(long long x){
    long long i=x;
    while(i<=n){
        if(a[i]*x-s[i]+s[i-x]<=m){return 1;}
        i++;
    }
    return 0;
}
void erfen(long long l,long long r){
    while(l<r){
        long long mid=(l+r+1)/2;
        if(mycheck(mid))l=mid;
        else r=mid-1;
    }
    ans=l;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++)s[i]=s[i-1]+a[i];
    erfen(1,n);
    cout<<ans;
    return 0;
}

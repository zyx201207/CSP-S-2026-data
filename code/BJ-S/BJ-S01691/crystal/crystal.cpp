#include<bits/stdc++.h>
using namespace std;
long long a[500005],s[500005];
long long n,m;
bool check(long long x){
    for(int i=1;i<=n;i++){
        s[i]=0;
    }
    for(int i=1;i<x;i++){
        s[x]+=a[x]-a[i];
    }
    long long minn=s[x];
    for(int i=x+1;i<=n;i++){
        s[i]=s[i-1]-(a[i-1]-a[i-x])+(a[i]-a[i-1])*(x-1);
        minn=min(minn,s[i]);
    }
    return minn<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n+1);
    long long l=1,r=n;
    while(l<r){
        int mid=(l+r+1)/2;
        if(check(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    printf("%lld\n",l);
    return 0;
}
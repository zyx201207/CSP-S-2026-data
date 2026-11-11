#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long ans,o;
long long cal(long long x){
    long long cnt=0;
    for(long long i=x;i>=1;i--){
        if(o>=(a[x]-a[i])){
            o-=(a[x]-a[i]);
            cnt++;
        }
    }
    return cnt;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    long long l=1,r=n;
    while(l<r){
        long long mid=(l+r)>>1;
        o=m;
        long long wpc=cal(mid);
        //cout<<l<<" "<<r<<" | "<<mid<<" "<<a[mid]<<" "<<o<<endl;
        if(wpc>=ans){
            ans=wpc;
            l=mid+1;

        }else{
            r=mid;
        }
    }
    long long p=(l+r)/2;
    o=m;
    for(long long i=((l+r)/2)+1;i<=n;i++){
        if(a[i]==a[i-1]){
            p=i;
        }
    }
    long long q=cal(p);
    //cout<<p<<" "<<a[p]<<" "<<cal(p)<<endl;
    ans=max(ans,q);
    //cout<<"wpc"<<endl;
    cout<<ans;
    return 0;
}


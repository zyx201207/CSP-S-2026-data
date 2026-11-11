#include<bits/stdc++.h>
using namespace std;
const long long N=2e5+10;
long long cmp(long long n,long long m){
    return n>m;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    long long a[N];
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+1+n,cmp);
    long long ans=0;
    if(m==1){
        cout<<a[1];
        return 0;
    }else if(m==n){
        ans=a[1]&a[2];
        for(long long i=3;i<=n;i++){
            ans=ans&a[i];
        }
        cout<<ans;
        return 0;
    }else if(m==2){
        long long maxans=0;
        for(long long i=1;i<=n;i++){
            for(long long j=i+1;j<=n;j++){
                ans=a[i]&a[j];
                maxans=max(ans,maxans);
            }
        }
        cout<<maxans;
        return 0;
    }
    return 0;
}

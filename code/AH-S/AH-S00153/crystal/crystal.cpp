#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long n,m,a[500005],q,ans;
bool check(long long t){
    q=0;
    for(int i=1;i<=t;i++) q+=a[t]-a[i];
    for(int j=t;j<=n;j++){
        if(q<=m) return 1;
        q-=a[j]-a[j-t+1];
        q+=(a[j+1]-a[j])*(t-1);
    }return 0;

}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    long long l=1,r=n,mid;
    while(l<=r){
        mid=(l+r)/2;
        if(check(mid)){
            ans=mid;
            l=mid+1;
        }else r=mid-1;

    }
    cout<<ans;
    return 0;
}

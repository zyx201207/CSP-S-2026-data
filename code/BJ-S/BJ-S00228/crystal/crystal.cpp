#include<bits/stdc++.h>
using namespace std;
const long long N=5e7+5;
long long n,m;
long long a[N],c[N]={},vis[N];
long long ans=1;
bool check(long long x){
    long long k=0,f=vis[a[x]];
    for(long long i=1;i<=x;i++){
        if(a[i]<a[x]){
            f++;
            k+=a[i];
        }
    }
    if(k<=m){
        ans=max(ans,f);
        return 1;
    }
    return 0;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        vis[a[i]]++;
    }
    sort(a+1,a+n+1);
    c[0]=a[1];
    for(long long i=2;i<=n;i++)c[i]=a[i]-c[i-1];

    long long l=1,r=n,mid;
    while(l<=r){
        mid=(l+r+1)/2;
        //cout<<"mid="<<mid<<endl;
        if(check(mid)){
            //ans=mid;
            l=mid+1;
        }else r=mid-1;
    }
    cout<<ans<<endl;
    return 0;
}

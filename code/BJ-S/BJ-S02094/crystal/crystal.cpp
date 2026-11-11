#include<bits/stdc++.h>
using namespace std;
long long ans=1,n,m;
long long a[500009],b[500009],c[500009],am=0;
bool cmp(long long a,long long b){
    return a>b;
}
long long lrs(long long l,long long r){
    return (c[r]-c[l-1])-(r-l+1)*b[l];
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        am=max(am,a[i]);
    }
    sort(a+1,a+n+1,cmp);
    for(long long i=1;i<=n;i++){
        b[i]=am-a[i];
    }
    for(long long i=1;i<=n;i++){
        c[i]=c[i-1]+b[i];
        //cout<<c[i]<<" ";
    }
    //cout<<"\n"<<lrs(1,4)<<"\n";
    long long l=1,r=1;
    for(;l<=n;l++){
        while(r<n&&m>=lrs(l,r+1)){
            r++;
        }
        ans=max(ans,r-l+1);
        //cout<<l<<" "<<r<<"\n";
    }
    cout<<ans;
}

#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005],d[500005];
bool check(long long x){
    long long m1=LONG_LONG_MAX;
    for(int i=x;i<=n;i++){
        m1=min(m1,c[i]*(x-1)-(d[i-1]-d[i-x]));
    }
    return m1<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=n;i++){
        c[i]=b[i]+c[i-1];
    }
    for(int i=1;i<=n;i++){
        d[i]=c[i]+d[i-1];
    }
    long long l=0,r=n;
    while(l<=r){
        long long mid=(r-l)/2+l;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid-1;
        }
    }
    cout<<r;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

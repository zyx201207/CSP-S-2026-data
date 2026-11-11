#include <bits/stdc++.h>
using namespace std;
long long a[5000005],b[5000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(long long i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n-1;i++) b[i]=a[i+1]-a[i];
    long long r=1,l=1,c=0,d=0;
    while(r<=n-1){
        while(c<=m&&r<=n-1){
            c+=b[++r];
        }
        d=max(d,r-l-1);
        while(c>m){
            c-=b[++l];
        }
        d=max(d,r-l+1);
    }
    cout<<d-1;
    return 0;
}

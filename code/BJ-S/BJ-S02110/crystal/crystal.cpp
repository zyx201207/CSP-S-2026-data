#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],mx;

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    sort(a+1,a+n+1);
    for(long long i=1;i<=n;i++){
        b[i]=b[i-1]+a[i];
        if(m+b[i]>=a[i]*i)mx=mx>i?mx:i;
    }
    cout<<mx;
    //for(int i=1;i<=n;i++)cout<<a[i]<<' ';
}

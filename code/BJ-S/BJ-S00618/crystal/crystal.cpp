#include<bits/stdc++.h>
using namespace std;
long long m,n;
long long a[500005],b[500005],sum[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>a[i];
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++) b[i]=a[i]-a[i-1];
    for(int i=2;i<=n;i++) c[i]=c[i-1]+b[i];
    for(int i=2;i<=n;i++){
        sum[i]=sum[i-1]+(i-1)*(a[i]-a[i-1]);
    }
    int j=1,i=1;
    long long cnt=0;
    while(i<=n&&j<=n){
        long long s=sum[j]-sum[i]-(i-1)*(a[j]-a[i]);
        if(s<=m){
            if(j-i+1>cnt) cnt=j-i+1;
            j++;
        }else i++;
    }
    cout<<cnt;
    return 0;
}

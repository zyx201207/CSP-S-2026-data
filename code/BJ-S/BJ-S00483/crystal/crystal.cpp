#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],sum[500005],dcsl[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>n>>m;
    bool bb=1,bb2=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        sum[i]=sum[i-1]+a[i];
        if(a[i]!=i){
            bb=0;
        }
        if((a[i]-a[i-1]!=a[2]-a[1])&&i>=2){
            bb2=0;
        }
    }
    if(bb){
        for(int i=1;i<=n;i++){
            dcsl[i]=dcsl[i-1]+i;
            if(m<dcsl[i]){
                cout<<i;
                return 0;
            }
        }
    }
    if(bb2){
        for(int i=1;i<=n;i++){
            if(m<(a[2]-a[1])*dcsl[i]){
                cout<<i;
                return 0;
            }
        }
    }
    sort(a+1,a+n+1);
    for(int j=n;j>0;j--){
        for(int i=1;i<=n-j+1;i++){
            if(((sum[i+j-1]-sum[i-1]+m)>=(j*a[i+j-1]))){
                cout<<j;
                return 0;
            }
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long a[100000005];
long long qzh[100000005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    long long n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++) cin>>a[i];
    if(n==1){
        cout<<1;
        return 0;
    }
    if(n==2&&(a[0]+m>=a[1]||a[1]+m>=a[0])){
        cout<<2;
        return 0;
    }
    sort(a,a+n);
    qzh[0]=a[0];
    for(int i=1;i<n;i++) qzh[i]==qzh[i-1]+a[i];
    int ans=0;
    for(int i=0;i<n;i++){
        if(qzh[i]+m>=a[i+1]*i+1) ans=i+2;
        else break;
    }
    cout<<ans;
    return 0;
}

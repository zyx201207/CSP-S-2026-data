#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],num=0,ans=0;
int main(){

    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
        num += a[i];
    }
    num /= n;
    for(long long i=1;i<=n;i++){
        a[i] = abs(num-a[i]);
    }
    for(long long i=1;i<=n;i++){
        if(a[i]<0){
            continue;
        }
        if(m>=a[i]){
            m -= a[i];
            ans++;
        }
    }
    cout<<ans;

    return 0;
}

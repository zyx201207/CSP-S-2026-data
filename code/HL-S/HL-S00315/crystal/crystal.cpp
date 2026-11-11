#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[550000],sub[550000],s[550000];
int main(){
#ifndef HCX
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    ll m;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sub[i]=a[i]-a[i-1];
        s[i]=sub[i]+s[i-1];
        if(i==1)s[i]=0;
        // cout<<sub[i]<<" "<<s[i]<<"\n";
    }
    s[1]=0;
    ll tsum=0;
    int ans=0;
    for(int i=2,j=1;i<=n;){
        while(tsum<=m&&j<=n){
            j++;
            tsum+=sub[j]*(j-i+1);
        }
        if(tsum>m){
            tsum-=sub[j]*(j-i+1);
            j--;
        }
        if(j>n)j--;
        // cout<<i<<" "<<j<<" "<<tsum<<" "<<s[j]-s[i-1]<<"\n";
        ans=max(ans,j-i+2);
        tsum-=s[j]-s[i-1];
        i++;
    }
    cout<<ans<<"\n";
    return 0;
}
// build:
// g++ crystal.cpp -o crystal -O2 -Wall -Wextra -Wconversion -Wshadow
// debug:
// g++ crystal.cpp -o crystal -DHCX -g -fsanitize=address,undefined -Wall -Wextra -Wconversion -Wshadow
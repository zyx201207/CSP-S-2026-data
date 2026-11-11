#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll a[220000];
char c[220000];
int m=0;
int main(){
#ifndef HCX
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin>>n;
    ll sum=0;
    for(int i=1;i<=n;i++){
        ll t;char cc;
        cin>>t>>cc;
        if(c[m]==cc){
            a[m]+=t;
        }else{
            a[++m]=t;
            c[m]=cc;
        }
        sum+=t;
    }
    if(m==1){
        cout<<"0\n";
        return 0;
    }
    ll mid=sum/2;
    if(sum&1)mid-=1;
    // r->l;
    int i=1,j=m;
    ll si=0,sj=0;
    ll di=a[i],dj=a[j];
    ll ans=0;
    while(si<=mid&&i<=j){
#ifdef HCX
        cerr<<i<<" "<<j<<" "<<di<<" "<<dj<<" "<<si<<" "<<sj<<":"<<ans<<"\n";
#endif
        if(c[i]==c[j]){
            ll mn=min(di,dj);
            di-=mn,dj-=mn;
            si+=mn,sj+=mn;
        }else{
            ll mn=min(di,dj);
            ans+=mn;
            di-=mn,dj-=mn;
            si+=mn,sj+=mn;
        }
        while(di<=0&&si<=mid){
            di+=a[++i];
        }
        while(dj<=0&&sj<=mid){
            dj+=a[--j];
        }
    }
    cout<<ans<<"\n";
    return 0;
}
// compile:
// g++ string.cpp -o string -O2 -std=c++14 -Wall -Wextra -Wconversion -Wshadow 2> log.txt
// debug
// g++ string.cpp -o string -fsanitize=address,undefined -g -DHCX -std=c++14 -Wall -Wextra -Wconversion -Wshadow 
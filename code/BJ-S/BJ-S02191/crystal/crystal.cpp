#include<iostream>
#include<algorithm>
#include<cstdio>
#define ll long long
using namespace std;
ll a[500005],s[500005],c[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m;
    scanf("%lld%lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",a+i);
    }
    sort(a+1,a+n+1);
    ll maxx=1;
    s[1]=1;c[1]=0;
    for(ll i=2;i<=n;i++){
        s[i]=s[i-1]+1;
        c[i]=c[i-1]+(a[i]-a[i-1])*s[i-1];
        while(c[i]>m){
            c[i]-=(a[i]-a[i-s[i]+1]);
            s[i]--;
        }
        maxx=max(maxx,s[i]);
    }
    printf("%lld",maxx);
    return 0;
}

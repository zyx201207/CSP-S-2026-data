#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define X 500005
#define g() getchar_unlocked()
ll re(){
    ll k=0,f=1;char ch=g();
    for(;!isdigit(ch);ch=g())if(ch=='-')f=-1;
    for(;isdigit(ch);ch=g())k=(k<<1)+(k<<3)+(ch^48);
    return k*f;
}
ll n,m,a[X],c[X],l,r,sum,ans=1;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=re(),m=re();
    for(ll i=1;i<=n;i++)a[i]=re();
    sort(a+1,a+n+1);
    for(ll i=1;i<n;i++)c[i]=a[i+1]-a[i],a[i]=0;
    for(ll i=1;i<n;i++)a[i]=a[i-1]+c[i];
    a[n]=0;n--;
    l=n+1,r=n;
    while(l--){
        if(l==0)break;
        sum=sum+a[r]-a[l-1];
        while(sum>m&&l<=r)sum-=c[r]*(r-l+1),r--;
        ans=max(ans,r-l+2);
    }
    cout<<ans;
    return 0;
}

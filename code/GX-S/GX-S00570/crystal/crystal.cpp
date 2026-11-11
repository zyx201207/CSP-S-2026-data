#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll r(){
    ll s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')w*=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        s=s*10+ch-'0';
        ch=getchar();
    }
    return s*w;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ll n,m,a[500005],c[500005];
    n=r();m=r();
    bool t1=1;
    for(ll i=1;i<=n;i++){
        a[i]=r();
        if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2])t1=0;
    }
    sort(a+1,a+n+1);
    if(t1){
        ll k=1,q=0,d=a[2]-a[1];
        while(q<=m){
            k++;q=a[1]*k+k*(k-1)/2*d;
        }
        printf("%lld",k);
        return 0;
    }//special A and B
    ll ans=-1;
    for(ll p=1;p<=n;p++){
        for(int i=1;i<=n;i++)c[i]=0;
        for(ll i=p+1;i<=n;i++){
            c[i]=(a[i]-a[i-1])*(i-p)+c[i-1];
            if(c[i]>m){
                ans=max(ans,i-p);
                break;
            }
            if(c[i]<=m&&i==n)ans=max(ans,i-p+1);
        }
    }
    if(ans!=-1)printf("%lld",ans);
    else printf("%lld",n);
    return 0;
}

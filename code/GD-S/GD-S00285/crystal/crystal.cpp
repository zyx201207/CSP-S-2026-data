#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
const int M=18;
ll rd(){
    ll f=1,s=0;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) s=s*10+(c^48);
    return f*s;
}
int n,ans;
ll a[N],s[N],m;

ll check(int l,int r){
    return 1ll*(r-l+1)*a[r]-(s[r]-s[l-1]);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd(),m=rd();
    for(int i=1;i<=n;i++) a[i]=rd();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i];

    for(int l=1;l<=n;l++){
        int L=l,R=n,r=l;
        while(L<=R){
            int mid=(L+R>>1);
            if(check(l,mid)<=m) r=mid,L=mid+1;
            else R=mid-1;
        }
        ans=max(ans,r-l+1);
    }
    cout<<ans;
    return 0;
}
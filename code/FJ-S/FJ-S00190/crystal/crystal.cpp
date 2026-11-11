#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline ll rd(){
    char ch=getchar();
    ll f=1,x=0;
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-48;
        ch=getchar();
    }
    return x*f;
}
const ll N_ = 5e5+10;
ll sum[N_],a[N_],N,M,ans;
inline bool check(ll l,ll r){
    return sum[r]-sum[l-1]+M>=(r-l+1)*a[r];
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    N=rd();M=rd();
    for(int i=1;i<=N;i++)a[i]=rd();
    sort(a+1,a+1+N);
    for(int i=1;i<=N;i++)sum[i]=sum[i-1]+a[i];
    for(int i=1;i<=N;i++){
        ll r=i,l=1,R=i;
        while(l<r){
            ll mid=l+r>>1;
            if(check(mid,R))r=mid;
            else l=mid+1;
        }
        ans=max(ans,R-l+1);
    }
    cout<<ans;
    return 0;
}
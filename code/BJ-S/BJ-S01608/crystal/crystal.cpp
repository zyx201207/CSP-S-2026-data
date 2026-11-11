#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m;
ll a[N],pre[N],ans;
ll read(){
    ll x=0*1ll,f=1ll;
    char ch=getchar();
    while(ch>'9'||ch<'0'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10*1ll+ch-'0';
        ch=getchar();
    }
    return x*f;
}
bool check(int i,int x){
    ll p=pre[i]-pre[x-1];
    ll pc=(i-x+1ll)*a[i]-p;
    return pc<=m;
}
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        int l=1,r=i;
        ll cnt=1ll;
        while(l<=r){
            int mid=l+r>>1;
            if(check(i,mid)){
                cnt=mid;
                r=mid-1;
            }else l=mid+1;
        }
        ans=max(ans,max((ll)i-cnt+1ll,1ll));
    }
    printf("%lld",ans);
    return 0;
}

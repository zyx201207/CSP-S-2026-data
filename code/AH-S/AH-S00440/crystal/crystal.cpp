#include<bits/stdc++.h>
#define OpenFile(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define CloseFile fclose(stdin),fclose(stdout)
#define getchar getchar_unlocked
#define rep(x,y,z) for(int x=(y);x<=(z);++x)
#define per(x,y,z) for(int x=(y);x>=(z);--x)
#define int long long
#define N 500005
using namespace std;
int get(int ans=0,int x=1){
    char ch=getchar();
    while(ch<48||ch>57){if(ch=='-')x=-1;ch=getchar();}
    while(ch>=48&&ch<=57)ans=(ans<<1)+(ans<<3)+ch-48,ch=getchar();
    return ans*x;
}int n,m,pre[N],sum[N],a[N],ans;
int calc(int l,int r){return pre[r]-(l-1)*a[r]+sum[l-1];}
signed main(){
    OpenFile(crystal);
    n=get(),m=get();
    rep(i,1,n)a[i]=get();
    sort(a+1,a+1+n);
    rep(i,1,n)pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]),sum[i]=sum[i-1]+a[i];
    rep(i,1,n){
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(calc(mid,i)>m)l=mid+1;
            else r=mid;
        }ans=max(ans,i-l+1);
    }printf("%lld",ans);
    CloseFile;
    return 0;
}

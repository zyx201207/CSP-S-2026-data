#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define pii pair<int,int>
#define x first
#define y second
inline ll read(){
    ll d=0,f=0;char ch=getchar();
    while (!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while (isdigit(ch)) d=d*10+ch-'0',ch=getchar();
    return f?-d:d;
}
const int N=500005;

ll n,m,a[N],sum[N];

inline ll get(int l,int r) {return sum[r]-sum[l-1];}

inline void solve(){
    n=read(),m=read();
    for (int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
    int ans=1;
    for (int i=1;i<=n;i++){
        int l=1,r=i,mid,ret=i;
        while (l<=r){
            mid=l+r>>1;
            if (a[i]*(i-mid+1)-get(mid,i)<=m) ret=mid,r=mid-1;
            else l=mid+1; 
        }
        ans=max(ans,i-ret+1);
    }
    printf("%d\n",ans);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    // auto st=clock();
    solve();
    // cerr<<"cost:"<<1000*(clock()-st)/CLOCKS_PER_SEC<<"ms\n";
    return 0;
}
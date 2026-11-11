#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<"="<<x<<endl
#define gc getchar_unlocked
#define pc putchar_unlocked
#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define i128 __int128
#define rep(i,a,b) for(int i=a;i<=b;++i)
#define per(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
namespace IO{
    template<typename T>
    inline void read(T &x){
        x=0;bool fl=1;
        char c=gc();
        while(c<'0'||c>'9'){if(c=='-')fl=0;c=gc();}
        while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+(c^48),c=gc();
        x=fl?x:-x;
    }
    template<typename T>
    inline void write(T x){
        if(x<0) pc('-'),x=-x;
        if(x>9) write(x/10);
        pc(x%10+'0');
    }
}using namespace IO;
const int N=5e5+5;
int n;ll m;
ll a[N],s[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n),read(m);
    rep(i,1,n) read(a[i]);
    sort(a+1,a+n+1);
    rep(i,1,n) s[i]=s[i-1]+a[i];
    int ans=0;
    rep(i,1,n){
        int l=1,r=i,p=0;
        while(l<=r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-s[i]+s[mid-1]<=m) p=mid,r=mid-1;
            else l=mid+1;
        }
        ans=max(ans,i-p+1);
    }
    write(ans);
    return 0;
}
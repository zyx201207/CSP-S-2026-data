#include<bits/stdc++.h>
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define fi first
#define se second
#define m_p make_pair
#define p_b push_back
#define mid ((l+r)>>1)
#define ls k<<1
#define rs k<<1|1
#define lowbit(x) (x&(-x))
#define ALL(x) (x).begin(),(x).end()
using namespace std;

int rd(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-') f*=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch-'0'),ch=getchar();
    return x*f;
}
const int N=5e5+5;
int a[N],n,m,sum[N];
int calc(int l,int r,int w){
    int lim=r,res=r+1;
    while(l<=r){
        if(w*(lim-mid+1)-(sum[lim]-sum[mid-1])<=m) res=mid,r=mid-1;
        else l=mid+1;
    }return lim-res+1;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=rd(),m=rd();
    for(int i=1;i<=n;i++)a[i]=rd();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];
    int ans=1;
    for(int i=2;i<=n;i++)ans=max(ans,1+calc(1,i-1,a[i]));
    printf("%lld\n",ans);
    return 0;
}
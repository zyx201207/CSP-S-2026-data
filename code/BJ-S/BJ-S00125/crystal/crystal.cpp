#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=500010;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,m,a[MAXN],ans;
void slv(){
    n=read(),m=read();
    for(int i=1;i<=n;i++)a[i]=read();
    sort(a+1,a+n+1);
    for(int l=1,r=1,sum=a[1];r<=n;r++,sum+=a[r]){
        while(l<r&&(r-l+1)*a[r]-sum>m)sum-=a[l],l++;
        ans=max(ans,r-l+1);
    }
    printf("%lld\n",ans);

}
signed main(){
    freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
    slv();
    return 0;
}
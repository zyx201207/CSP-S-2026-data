#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int Max(int x,int y){return x<y?y:x;}
inline ll read(){
    ll sum=0,f=1; char c=getchar();
    for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-f;
    for(;'0'<=c&&c<='9';c=getchar()) sum=(sum<<1)+(sum<<3)+c-'0';
    return sum*f;
}
/*-----------------*/
const int N=5e5+10;
int n,ans; ll m,a[N],now;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+n+1);
    for(int l=1,r=1;r<=n;r++){
        while(now>m){now-=a[r]-a[l];l++;}
        ans=Max(ans,r-l+1);
        if(r<=n) now+=1ll*(r-l+1)*(a[r+1]-a[r]);
    }
    printf("%d\n",ans);
    return 0;
}
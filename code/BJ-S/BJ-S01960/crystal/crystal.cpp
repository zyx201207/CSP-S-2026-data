#include<bits/stdc++.h>
#define int long long
using namespace std;
inline void read(int &x){
    x=0;bool neg=0;char c=getchar();
    for(;!isdigit(c);c=getchar())neg=(c=='-');
    for(;isdigit(c);c=getchar())x=(x<<1)+(x<<3)+(c^48);
    if(neg)x=-x;
}
inline void chmx(int &x,int y){
    x<y?x=y:0ll;
}
int n,m,a[500005];
void slv(){
    read(n),read(m);
    for(int i=1;i<=n;i++)read(a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    for(int i=1,j=1,s=a[1];i<=n;i++,s+=a[i]){
        while(a[i]*(i-j+1)-s>m)s-=a[j],j++;
        // cout<<ans<<" "<<s<<" "<<j<<" "<<i<<endl;
        chmx(ans,i-j+1);
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    slv();
}
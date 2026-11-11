#include<bits/stdc++.h>
using namespace std;
inline char gtchar(){
    static char buf[1<<21],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++;
}
inline long long read(){
    char ch=gtchar();
    long long x=0;
    bool f=0;
    while(ch<'0'||ch>'9') f|=ch=='-',ch=gtchar();
    while(ch>='0'&&ch<='9') x=(x<<1)+(x<<3)+(ch^48),ch=gtchar();
    return f?-x:x;
}
int n,ans;
long long m,a[500005],sum[500005];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        int l=1,r=i;
        while(l<r){
            int mid=(l+r)>>1;
            if(a[i]*(i-mid+1)-(sum[i]-sum[mid-1])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,i-l+1);
    }
    cout<<ans;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
    int s=0,w=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
    return s*w;
}
const int N=2e6+5;
int x[N],L[N],R[N],cntl[N],cntr[N],a[N],b[N];
void solve(){
    int n=read(),d=read(),l=1,r=1,ans=0;
    for(int i=1;i<=n;i++)x[i]=read();
    for(int i=1;i<=n;i++){r=max(r,i);
        while(r<n&&x[r+1]-x[i]<=d)r++;R[i]=r;
    }for(int i=1;i<=n;i++){
        while(x[i]-x[l]>d)l++;L[i]=l;
    }for(int i=1;i<=n;i++){
        if(R[i]>i)cntr[R[i]]++;
        if(L[i]<i)cntl[L[i]]++;
    }for(int i=1;i<=n;i++){
        a[i]=1+cntr[i];int p=L[i];
        if(p<i&&R[p]==i)a[i]+=a[p]-1;
    }for(int i=n;i>=1;i--){
        b[i]=1+cntl[i];int q=R[i];
        if(q>i&&L[q]==i)b[i]+=b[q]-1;
    }for(int i=1;i<n;i++){int j=i+1;
        int l=cntr[j];if(R[i]==j)l--;
        int r=cntl[i];if(L[j]==i)r--;
        int p=L[i];if(p<i&&R[p]==j)l+=a[p]-1;
        int q=R[j];if(q>j&&L[q]==i)r+=b[q]-1;
        ans+=l*r;
    }cout<<ans<<"\n";
    for(int i=1;i<=n;i++)cntr[i]=cntl[i]=0;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    read();int t=read();
    while(t--)solve();
    return 0;
}

//g++ -std=c++14 -O2 C.cpp -o C
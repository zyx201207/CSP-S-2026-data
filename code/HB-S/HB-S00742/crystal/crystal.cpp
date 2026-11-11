#include <bits/stdc++.h>
using namespace std;
namespace fastio{
   template<typename T>
   inline void read(T& x){
    x=0;T f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    x*=f;
   }
   template<typename T>
   inline void write(T x){
    if(x<0){putchar('-');x=-x;}
    if(x>9){write(x/10);}
    putchar('0'+x%10);
   }
}
using namespace fastio;
using ll=long long ;
using i128=__int128;
using ull=unsigned long long;
const int N=5e5+7;
i128 A[N];
i128 sum[N];
int n,m;

i128 dis(int a,int b){
   return A[b]*(b-a)-(sum[b-1]-sum[a-1]);
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;i++){
     read(A[i]);
    }
    sort(A+1,A+1+n);
    for(int i=1;i<=n;i++){
     sum[i]=sum[i-1]+A[i];
    }
    int ans=1;
    for(int i=1;i<=n;i++){
     int l=1,r=i;
     while(l<r){
     int mid=(l+r)>>1;
     if(dis(mid,i)>m){l=mid+1;}
     else{r=mid;}
     }
     ans=max(ans,i-r+1);
    }
    write(ans);
    putchar('\n');
    return 0;
}
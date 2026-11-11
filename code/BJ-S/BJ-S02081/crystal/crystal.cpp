#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 500005

inline LL read(){
    char ch=getchar();
    int w=1;
    LL p=0;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void write(LL x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar('0'+x%10);
}
inline int readI(){
    char ch=getchar();
    int w=1;
    int p=0;
    while(ch<'0'||'9'<ch){
        if(ch=='-')w=-w;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        p=(p<<3)+(p<<1)+(ch^48);
        ch=getchar();
    }
    return p*w;
}
inline void writeI(int x){
    if(x<0)putchar('-'),x=-x;
    if(x>9)write(x/10);
    putchar('0'+x%10);
}

LL a[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n=readI();
    LL m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }

    sort(a+1,a+n+1);

    int l=n,ans=0;
    LL need=0;

    for(int r=n;r>=1;r--){
        while(1){
            if(need+a[r]-a[l-1]<=m&&l>=2)need+=a[r]-a[--l];
            else break;
        }
     //   printf("l:%lld r:%lld\n",l,r);
        ans=max(ans,r-l+1);
        need-=(r-l+1)*(a[r]-a[r-1]);
        if(l==1)break;
    }
    write(ans);
    return 0;
}

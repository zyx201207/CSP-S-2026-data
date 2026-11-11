#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define BIT 32
#define N 200005

inline LL read(){
    char ch=getchar();
    LL p=0;
    int w=1;
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
    putchar(x%10+'0');
}
inline int readI(){
    char ch=getchar();
    int p=0;
    int w=1;
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
    putchar(x%10+'0');
}

int cnt[BIT];
LL a[N];
bool ban[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n=readI(),m=readI();
    LL ans=0;

    for(int i=1;i<=n;i++){
        a[i]=read();
        for(int j=0;j<BIT;j++){
            if((a[i]>>j)&1)
                cnt[j]++;
        }
    }

    for(int i=BIT-1;i>=0;i--){
        if(cnt[i]>=m){
            ans|=(1<<i);
            for(int j=1;j<=n;j++){
                if(ban[j])continue;
                if(!((a[j]>>i)&1)){
                    ban[j]=1;
                    for(int k=0;k<BIT;k++)
                        if((a[j]>>k)&1)
                            cnt[k]--;
                }
            }
        }
    }

    write(ans);
    return 0;
}

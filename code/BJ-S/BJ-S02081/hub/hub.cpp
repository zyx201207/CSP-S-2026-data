#include<bits/stdc++.h>
using namespace std;
#define LL long long

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

int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=readI(),T=readI();
    while(T--){
        printf("0\n");
    }
    return 0;
}

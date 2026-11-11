#include<bits/stdc++.h>
using namespace std;
#define LL long long
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

struct node{
    int num;
    char ch;
}a[N];

bool check(int bigpos1,int pos1,int bigpos2,int pos2){
    if(bigpos1<bigpos2)return 1;
    else if(bigpos1==bigpos2){
        if(pos1<pos2)return 1;
        else return 0;
    }
    else return 0;
}

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n=readI();
    for(int i=1;i<=n;i++){
        a[i]={readI(),getchar()};
    }

    int bigpos1=1,pos1=1;
    int bigpos2=n,pos2=a[n].num;
    LL ans=0;

    while(check(bigpos1,pos1,bigpos2,pos2)){
        int temp=max(min(a[bigpos1].num-pos1,pos2),1);
        if(a[bigpos1].ch!=a[bigpos2].ch)ans+=temp;
        pos1+=temp,pos2-=temp;
        while(pos1>a[bigpos1].num){
            pos1-=a[bigpos1].num;
            bigpos1++;
        }
     //   cerr<<bigpos1<<' '<<pos1<<' '<<bigpos2<<' '<<pos2<<'\n';
        while(pos2<1){
            bigpos2--;
            pos2+=a[bigpos2].num;
        }
    }
    write(ans);
    return 0;
}
/*
1 6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b
*/

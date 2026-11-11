#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define N 2000005

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
struct node{
    int l,r;
};
vector<node>have[N];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int C=readI(),T=readI();
    if(1){
        while(T--){
            int n=readI();
            LL d=read();
            for(int i=1;i<=n;i++)a[i]=readI();
            int cnt=0,pos=n+1,pos2=0;
            for(int i=1;i<=n;i++){
                if(a[i]-a[1]<=d&&a[n]-a[i]<=d)
                    cnt++,pos=min(pos,i),pos2=max(pos2,i);
            }
            if(cnt==1){
                int k=pos-1;
                int l=n,r=n;
                for(int i=k;i<=n;i++){
                    if(a[i]-a[k]>d){
                        r=i-1;
                        break;
                    }
                }
                for(int i=k-1;i<=n;i++){
                    if(a[i]-a[k-1]>d){
                        l=i-1;
                        break;
                    }
                }
                write((r-l)*(k-2));
                putchar('\n');
            }
            else if(cnt==2){
                LL ans=(pos-1)*(n-pos2);
                int r=n;
                for(int l=pos-1;l>=1;l--){
                    while(a[r]-a[l]>d)
                        r--;
                    if(r<=pos2)break;
                    ans-=r-pos2;
                }
                write(ans);
                putchar('\n');
            }
            else{
                printf("0\n");
            }
        }
    }
    else{
        while(T--){
            int n=readI();
            LL d=read();
            for(int i=1;i<=n;i++)a[i]=readI();
            LL now=1;
            int lst=0;
            for(int i=1;i<=n;i++){
                bool flag=0;
                while(a[now+1]-a[i]<=d&&now+1<=n)now++,flag=1;
                for(int j=lst+1;j<=now;j++){
                    have[j].push_back({i,now});
                }
                if(flag)lst=i;
            }


            for(int i=1;i<=n;i++){
                printf("%lld :",i);
                for(int j=0;j<have[i].size();j++)
                    printf("{%lld,%lld},",have[i][j].l,have[i][j].r);
                printf("\n");
            }


        }
    }
    return 0;

}
/*
13 2
8 30
-10 0 5 10 20 25 30 50       0
8 20
-10 -5 -3 0 10 17 20 30      2
8 20
-15 -12 -10 -5 5 8 10 15     6
5 13
-10 -3 0 3 10                0

0 1
5 10
-10 -5 0 5 10
*/

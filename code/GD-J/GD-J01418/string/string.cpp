#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)
#define isdigit(c) (c>=48&&c<=57)
#define gc getchar
void read(int& x){
    x=0;int c=gc(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=gc();}
    x*=f;
}
void write(LL x){
    int stk[128],top=0;
    if(x<0) putchar('-'),x=-x;
    do{stk[++top]=x%10;x/=10;}while(x);
    while(top)putchar(stk[top--]|48);
}

const int MAXN=2e5+5;

int n;
int a[MAXN];
char c[MAXN];
LL ans;

void solve(){
    read(n);
    For(i,1,n){
        read(a[i]);
        scanf("%c", &c[i]);
    }
    int l = 1, r = n;
    while(l<r){
        if(a[l]>=a[r]){
            if(c[l]!=c[r]) ans += a[r];
            a[l] -= a[r];
            --r;
        }else{
            if(c[l]!=c[r]) ans += a[l];
            a[r] -= a[l];
            ++l;
        }
    }
    write(ans);
}

signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    solve();
    return 0;
}

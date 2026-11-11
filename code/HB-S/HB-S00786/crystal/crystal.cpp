#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
template<typename tp> inline void cmin(tp &a,tp b){(b<a)&&(a=b);}
template<typename tp> inline void cmax(tp &a,tp b){(b>a)&&(a=b);}
template<typename tp> inline void read(tp &x){
    x=0;tp f=1;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+(ch^48);ch=getchar();}
    x*=f;
}
template<typename tp> inline void write(tp x){
    static char stk[40];
    int top=0;
    if(x<0) putchar('-'),x=-x;
    do stk[++top]=x%10+48,x=x/10; while(x);
    while(top) putchar(stk[top--]);
}
const int N=5e5+10;
int n;
ll m;
ll a[N];
ll sum[N];
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    read(n);
    read(m);
    for(int i=1;i<=n;i++){
        read(a[i]);
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        sum[i]+=sum[i-1]+a[i];
    }
    auto qry=[&](int l,int r) -> ll {
        return a[r]*(r-l+1)-(sum[r]-sum[l-1]);
    };
    int ans=0;
    for(int i=1,j=1;i<=n;i++){
        while(qry(j,i)>m){
            j++;
        }
        cmax(ans,i-j+1);
    }
    printf("%d\n",ans);
    return 0;
}
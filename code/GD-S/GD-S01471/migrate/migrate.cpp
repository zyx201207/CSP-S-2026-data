#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
//#define int LL
#define For(i,t,n) for(int i=t;i<=n;++i)
#define foR(i,t,n) for(int i=t;i>=n;--i)
#define isdigit(c) (c>=48&&c<=57)
#define gc getchar
void read(int &x){
    x=0;int c=gc(),f=1;
    while(!isdigit(c)){if(c=='-')f=-1;c=gc();}
    while(isdigit(c)){x=(x<<3)+(x<<1)+(c^48);c=gc();}
    x*=f;
}
void write(int x){
    int stk[100],top=0;
    if(x<0)putchar('-'),x=-x;
    do{stk[++top]=x%10;x/=10;}while(x);
    while(top)putchar(stk[top--]|48);
}
const int MAXN=2e6+5;
int C,ans;
int n,d;
int x[MAXN],v[MAXN],s[MAXN];
void solve(){
    read(n);
    read(d);
    For(i, 1, n) read(x[i]);
    For(c,1,n){
        v[c] = 0;
        For(i, c + 1, n) v[i] = 1e9;
        For(i,c,n){
            For(j,i+1,n){
                if(x[i]+d<x[j])
                    break;
                if(v[i]+1<v[j])
                    v[j] = v[i] + 1, s[j] = 1;
                else if(v[i]+1==v[j])
                    ++s[j];
            }
        }
        For(i,c+1,n){
            if(s[i]==2)
                ++ans;
        }
    }
    write(ans);
    putchar('\n');
}

signed main(){

    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    read(c);
    read(t);
    while(t--) solve();
    return 0;
}

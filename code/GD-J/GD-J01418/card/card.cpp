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
void write(int x){
    int stk[128],top=0;
    if(x<0) putchar('-'),x=-x;
    do{stk[++top]=x%10;x/=10;}while(x);
    while(top)putchar(stk[top--]|48);
}

const int MAXN=5e5+5;
const int MAXM = 3e5 + 5;

int n,m;
int a[MAXN];
int pos[MAXM];
int ans[MAXM];

void taskA(){
    bool f = 1;
    For(i, 1, n - 1) if (a[i] > a[i + 1]) f = 0;
    if(!f) return;
    For(i, 1, n) pos[a[i]] = i;
    For(i,1,m){
        write(pos[i]);
        putchar(" \n"[i == m]);
    }
    exit(0);
}

void solve(){
    read(n); read(m);
    For(i,1,n) read(a[i]);
    taskA();
    For(c,1,n){
        For(i,c,n){
            if(!pos[a[i]])
                pos[a[i]] = i;
            else{
                if(i-pos[a[i]]>m){
                    For(j,1,m){
                        if(pos[j]>pos[a[i]]&&pos[j]<i)
                            pos[j] = 0;
                    }
                }else{
                    For(j,pos[a[i]],i){
                        if(pos[a[j]]==j)
                            pos[a[j]] = 0;
                    }
                }
                pos[a[i]] = i;
            }
        }
        For(i, 1, m) if(pos[i]) ++ans[i], pos[i] = 0;
    }
    For(i, 1, m) write(ans[i]), putchar(" \n"[i == m]);
}

signed main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    solve();
    return 0;
}

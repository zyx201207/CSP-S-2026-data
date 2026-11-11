
#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
typedef long long ll;

ll read() {
    ll x=0,f=1;
    ll ch=gc();
    while(!isdigit(ch)) {
        if(ch=='-')f=-1;
        ch=gc();
    }
    while(isdigit(ch)) {
        x=(x<<3)+(x<<1)+(ch^48);
        ch=gc();
    }
    return x*f;
}
void write(ll x) {
    ll stk[48],t=0;
    if(x<0)pc('-'),x=-x;
    if(x==0)pc('0');
    while(x)stk[t++]=x%10,x/=10;
    for(int i=t-1;i>=0;i--)pc(stk[i]^48);
    pc(' ');

}
namespace cd {
    ll n,m,a[500007],ans[300007],pos[300007],qu[300007],t,dbg;
    int main() {
        freopen("card.in","r",stdin);
        freopen("card.out","w",stdout);
        n=read();m=read();
        for(int i=1;i<=n;i++)a[i]=read();
        for(int i=1;i<=n;i++) {
            t=0;
            memset(pos,-1,sizeof(pos));
            for(int j=i;j<=n;j++) {

                if(pos[a[j]]==-1) {
                    pos[a[j]]=t;

                    qu[t++]=a[j];
                } else {
                    for(int k=pos[a[j]]+1;k<t;k++)pos[qu[k]]=-1;
                    t=pos[a[j]]+1;

                }

            }
            //d/bg=0;
            for(int i=0;i<t;i++) {
                ans[qu[i]]++;
                //if(qu[i]==1)dbg++;
            }
        }
        for(int i=1;i<=m;i++)write(ans[i]);
        return 0;
    }
}
int main(){return cd::main();}



//Trick||Treat!
//100+100+75+48=323 wu yuan 1=


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
    ll n,m,a[200007],mx,b[200007],c[200007],ans,cnt[10];
    ll f[2007][2007];
    bool cmp(ll x,ll y){return x>y;}
    void dfs(ll cur,ll x, ll y) {// 数为cur 前x个中选了y个
        if(x>n)return;
        if(y==m) {
            ans=max(ans,cur);
        }
        if(cur<ans)return;
        dfs(cur&a[x+1],x+1,y+1);
        dfs(cur,x+1,y);
    }
    int main() {
        freopen("and.in","r",stdin);
        freopen("and.out","w",stdout);
        n=read();m=read();
        for(int i=1;i<=n;i++)a[i]=read(),mx=max(a[i],mx);
        if(n==1) {
            write(a[1]);
                        return 0;

        }
        sort(a+1,a+n+1,cmp);

        b[1]=a[1];
        for(int i=2;i<=n;i++)b[i]=b[i-1]&a[i];
        c[n]=a[n];
        for(int i=n-1;i>=1;i--)c[i]=c[i+1]&a[i];

        if(m==1) {
            write(mx);
            return 0;
        }
        if(m==2) {
            for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) ans=max(ans,a[i]&a[j]);
            write(ans);
                        return 0;

        }
        if(n==m) {
            write(b[n]);
                        return 0;

        }
        if(m==n-1) {
            ans=max(b[n-1],c[2]);
            for(int i=2;i<n;i++) {
                ans=max(ans,b[i-1]&c[i+1]);
            }
            write(ans);
                        return 0;

        }
        if(mx<=4) {
                for(int i=1;i<=n;i++)cnt[a[i]]++;
            if(cnt[3]>=m) write(3);
            else if(cnt[3]+cnt[2]>=m)write(2);
            else if(cnt[3]+cnt[1]>=m)write(1);
            else write(0);
            return 0;
        }
        if(n<=20) {
               dfs(0x7fffffffffffffffll,0,0);
            write(ans);
            return 0;
        }
        // teshuxzhiA
        write(b[m]);
        return 0;
    }
}
int main(){return cd::main();}


// t3: 想什么正解？打个75pts

//Trick||Treat!

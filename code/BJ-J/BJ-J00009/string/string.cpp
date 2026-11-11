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
    pc('\n');

}
namespace cd {
    ll n,l,a[200007],c[200007],cur=1,t=0,ans;
    struct nd {
        ll l,r;
        ll c;
    } s[200007],lf[200007],rf[200007];ll mid;ll lt,rt,fg;
    inline ll xb(ll i) {
        if(l%2==1&&i==l/2+1)return -1;
        if(i<=l/2) { //left
            return l/2-i+1;
        } else {
            return i-l/2-(l%2);
        }
    }
    int main() {
        freopen("string.in","r",stdin);
        freopen("string.out","w",stdout);
        n=read();
        for(int i=1;i<=n;i++) {
            a[i]=read();l+=a[i];
            c[i]=gc();
        }
        for(int i=1;i<=n;i++) {
            if(t!=0&&s[t-1].c==c[i]) {
                s[t-1].r=cur+a[i]-1;
                cur+=a[i];
            } else {
                s[t].c=c[i];
                s[t].l=cur;
                s[t].r=cur+a[i]-1;
                cur+=a[i];

                t++;
            }
        }
        cur=0;
        if(t==1) {
            write(0);return 0;
        }
        if(l%2==0) {
            for(int i=0;i<t;i++) {
                if(s[i].l<=l/2&&l/2<=s[i].r) mid=i;
            }
            if(s[mid].r==l/2) { // aab|caa
                for(int i=mid;i>=0;i--) {
                    lf[lt].l=xb(s[i].r);
                    lf[lt].r=xb(s[i].l);
                    lf[lt++].c=s[i].c;
                }
                for(int i=mid+1;i<t;i++) {
                    rf[rt].l=xb(s[i].l);
                    rf[rt].r=xb(s[i].r);
                    rf[rt++].c=s[i].c;
                }

            } else { // aabbba
                lf[lt].l=1;
                lf[lt].r=l/2-s[mid].l+1;
                lf[lt++].c=s[mid].c;
                rf[rt].l=1;
                rf[rt].r=s[mid].r-l/2;
                rf[rt++].c=s[mid].c;
                for(int i=mid-1;i>=0;i--) {
                    lf[lt].l=xb(s[i].r);
                    lf[lt].r=xb(s[i].l);
                    lf[lt++].c=s[i].c;
                }
                for(int i=mid+1;i<t;i++) {
                    rf[rt].l=xb(s[i].l);
                    rf[rt].r=xb(s[i].r);
                    rf[rt++].c=s[i].c;
                }

            }

        } else { // l%2==1
            for(int i=0;i<t;i++) {
                if(s[i].l<=l/2+1&&l/2+1<=s[i].r) mid=i;
            }
            if(s[mid].l==s[mid].r) {
                for(int i=mid-1;i>=0;i--) {
                    lf[lt].l=xb(s[i].r);
                    lf[lt].r=xb(s[i].l);
                    lf[lt++].c=s[i].c;
                }
                for(int i=mid+1;i<t;i++) {
                    rf[rt].l=xb(s[i].l);
                    rf[rt].r=xb(s[i].r);
                    rf[rt++].c=s[i].c;
                }
            } else if(s[mid].l==l/2+1){

                rf[rt].l=1;
                rf[rt].r=xb(s[mid].r);
                rf[rt++].c=s[mid].c;
                for(int i=mid-1;i>=0;i--) {
                    lf[lt].l=xb(s[i].r);
                    lf[lt].r=xb(s[i].l);
                    lf[lt++].c=s[i].c;
                }
                for(int i=mid+1;i<t;i++) {
                    rf[rt].l=xb(s[i].l);
                    rf[rt].r=xb(s[i].r);
                    rf[rt++].c=s[i].c;
                }
            } else if(s[mid].r==l/2+1) { // abb/b/aaa
                lf[lt].l=1;
                lf[lt].r=xb(s[mid].l);
                lf[lt++].c=s[mid].c;
                for(int i=mid-1;i>=0;i--) {
                    lf[lt].l=xb(s[i].r);
                    lf[lt].r=xb(s[i].l);
                    lf[lt++].c=s[i].c;
                }
                for(int i=mid+1;i<t;i++) {
                    rf[rt].l=xb(s[i].l);
                    rf[rt].r=xb(s[i].r);
                    rf[rt++].c=s[i].c;
                }

            } else { // abcccba
                lf[lt].l=1;
                lf[lt].r=xb(s[mid].l);
                lf[lt++].c=s[mid].c;
                rf[rt].l=1;
                rf[rt].r=xb(s[mid].r);
                rf[rt++].c=s[mid].c;
                for(int i=mid-1;i>=0;i--) {
                    lf[lt].l=xb(s[i].r);
                    lf[lt].r=xb(s[i].l);
                    lf[lt++].c=s[i].c;
                }
                for(int i=mid+1;i<t;i++) {
                    rf[rt].l=xb(s[i].l);
                    rf[rt].r=xb(s[i].r);
                    rf[rt++].c=s[i].c;
                }

            }
        }
        //for(int i=0;i<lt;i++) printf("lt%d %lld~%lld %c\n",i,lf[i].l,lf[i].r,(char)lf[i].c);
        //for(int i=0;i<rt;i++) printf("rt%d %lld~%lld %c\n",i,rf[i].l,rf[i].r,(char)rf[i].c);

        if(lt==rt) {
            for(int i=0;i<lt;i++) {
                if(lf[i].l==rf[i].l&&lf[i].r==rf[i].r&&lf[i].c==rf[i].c)continue;
                fg=1;break;
            }
            if(fg==0){write(0);return 0;}
        }
        for(ll lc=0,rc=0,rpos=1;lc<lt&&rc<rt;) {
            while(rf[rc].l<=lf[lc].r) {
                if(rf[rc].c!=lf[lc].c) {
                    ans+=min(rf[rc].r,lf[lc].r)-rpos+1;
                    //fprintf(stderr,"lc=%lld rc=%lld rpos=%lld ans+=%lld\n",lc,rc,rpos,rf[rc].r-rpos+1);
                } else {
                    //fprintf(stderr,"lc=%lld rc=%lld rpos=%lld pass\n",lc,rc,rpos);

                }
                if(rf[rc].r>=lf[lc].r) {
                    rpos=lf[lc].r+1;
                    //fprintf(stderr,"lc=%lld rc=%lld rpos=%lld(new) \n",lc,rc,rpos);

                    break;
                } else {
                    rpos=rf[rc].r+1;
                    rc++;
                    //fprintf(stderr,"lc=%lld rc=%lld(new) rpos=%lld(new) \n",lc,rc,rpos);

                }
                if(rc>rt)break;
            }
            lc++;
        }
        write(ans);
        return 0;
    }
}
int main(){return cd::main();}



//Trick||Treat!
// 08:54 完成T1 开T2
// 10:35 done t2
/*
：没有写输入文件虚空调试半天

luogu/1435654
beijing 101 high school KaoDians
*/

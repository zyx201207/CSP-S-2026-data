#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define gc getchar_unlocked
#define pc putchar_unlocked



ll read(){
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
    for(int i=t-1;i>=0;i--) {
        pc(stk[i]^48);
    }
    pc(' ');
}
namespace cd{
    ll n,m,a[500007],b[500007],cnt,lst,ans,mn,mp,nd;ll mx;
    /*ll lg2[500007],rmq[500007][20];
    ll rmqu(ll l,ll r) {
        ll k=lg2[r-l+1];
        return max(rmq[l][k],rmq[r-(1<<k)+1][k]);
    }*/
    ll bisect(ll lft) {
        ll l=lft,r=n;
        ll mid=l+(r-l)/2,ans=-1;
        while(l<=r) {// nd=a[j]*(j-i+1)-(b[j]-b[i-1]);
            mid=l+(r-l)/2;
            if(a[mid]*(mid-lft+1)-(b[mid]-b[lft-1])<=m) {
                ans=mid;
                l=mid+1;
            } else r=mid-1;
        }
        return ans;
    }

    int main() {
        freopen("crystal.in","r",stdin);
        freopen("crystal.out","w",stdout);
        n=read();m=read();for(int i=1;i<=n;i++)a[i]=read();
        sort(a+1,a+n+1);

        // O(n^2) zuo fa?
        // 15:32 opt to n log n? er fen? +Sprase table

        for(int i=1;i<=n;i++)b[i]=b[i-1]+a[i];
        /*
        tan xin shi jia de;
        lg2[1]=0;
        for(int i=2;i<=n;i++)lg2[i]=lg2[i>>1]+1;//;,write(lg2[i]);
        for(int i=1;i<=n;i++)rmq[i][0]=a[i];
        for(int j=1;(1<<j)<=n;j++) for(int i=1;i<=n-(1<<j)+1;i++) {
            rmq[i][j]=max(rmq[i][j-1],rmq[i+(1<<(j-1))][j-1]);
        }
        ll l=read(),r=read();
        write(rmqu(l,r));
        return 0;
        woshi nailong wodou gei xu lie pai xu le wo wei shen me yao ST biao?????
        */
        for(int i=1;i<=n;i++) {
            /*for(int j=i+1;j<=n;j++) {
                nd=a[j]*(j-i+1)-(b[j]-b[i-1]);
                if(nd<=m) ans=max(ans,j-i+1ll);
                else break;
            } O(n^2):*/
            nd=bisect(i);
            if(nd!=-1)ans=max(ans,nd-i+1ll);

        }
        write(ans);
        return 0;
    }
}
int main(){return cd::main();}

// woShiQU
//freopen
//woxihuannimen!
// nan yi 1=
// %%% julao
// luogu uid=1435654, @beijing101highSchoolKaodian.-104Seat1
// Oct31==Dec25?

#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
#define all(x) x.begin(),x.end()
#define int long long
#define rep(i,b,e) for(int i=(b);i<=(e);i++)
#define repd(i,b,e) for(int i=(b);i>=(e);i--)
int in(){
    int r=0;bool f=0;char c=gc();
    while(c<'0'||c>'9')f|=(c=='-'),c=gc();
    while(c>='0'&&c<='9')r=r*10+(c-'0'),c=gc();
    return f?-r:r;
}
void out(int x){
    if(x<0)pc('-'),x=-x;
    if(x<10)pc('0'+x);
    else out(x/10),pc('0'+(x%10));
}
void getmax(int&x,int y){x=y>x?y:x;}
void getmin(int&x,int y){x=y<x?y:x;}
const int N=2e6+5;
const int NN=5e3+5;
const int M=1e9+7;
const int INF=1e18;
int n,d;int x[N];
int a[N],p[N];
int dis[NN][NN],cnt[NN][NN];
int SP(){
    int ans=0;
    int pp=x[2]-x[1];
    pp=d/pp;
    if(pp==2){
        ans=n-2;
    }
    return ans;
}
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c=in(),_=in();
    while(_--){
        n=in(),d=in();int ans=0;
        rep(i,1,n)x[i]=in();
        int now=n;
        repd(i,n,1){
            while(x[now]-x[i]>d)now--;
            a[i]=now;
        }
        now=n;
        repd(i,n,1){
            while(a[now]>=i)now--;
            p[i]=now+1;
        }
        if(c==11||c==12){
            out(SP()),pc('\n');
            continue;
        }
        rep(len,1,n){
            rep(l,1,n-len+1){
                int r=l+len-1;
                if(l==r){
                    dis[l][r]=0;
                    cnt[l][r]=1;
                    continue;
                }
                dis[l][r]=INF;cnt[l][r]=0;
                rep(k,max(l,p[r]),r-1){
                    if(dis[l][k]+1<dis[l][r]){
                        dis[l][r]=dis[l][k]+1;
                        cnt[l][r]=0;
                    }
                    if(dis[l][k]+1==dis[l][r]){
                        cnt[l][r]+=cnt[l][k];
                    }
                }
                if(cnt[l][r]==2)ans++;
            }
        }
        out(ans),pc('\n');
    }
    return 0;
}

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
const int N=1e6+5;
const int M=1e9+7;
const int INF=1e18;
int n,m;int a[N],pre[N];
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=in(),m=in();
    rep(i,1,n)a[i]=in();
    sort(a+1,a+1+n);int ans=0;
    rep(i,1,n)pre[i]=pre[i-1]+a[i];
    int l=1;
    rep(r,1,n){
        while(a[r]*(r-l+1)-(pre[r]-pre[l-1])>m)l++;
        getmax(ans,r-l+1);
    }
    out(ans);
    return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
namespace fastIO{
    const int IN_BUF=1<<20;
    char inbuf[IN_BUF],*p1=inbuf,*p2=inbuf;
    inline int gc(){
        if(p1==p2){
            p2=(p1=inbuf)+fread(inbuf,1,IN_BUF,stdin);
            if(p1==p2) return EOF;
        }
        return *p1++;
    }
    inline int read(){
        int k=0,f=1;
        int c=gc();
        while(c!=EOF&&!isdigit(c)){
            if(c=='-') f=-1;
            c=gc();
        }
        if(c==EOF) return 0;
        while(c!=EOF&&isdigit(c)){
            k=(k<<1)+(k<<3)+(c^48);
            c=gc();
        }
        return k*f;
    }
    const int OUT_BUF=1<<22;
    char outbuf[OUT_BUF],*now=outbuf;
    inline void pc(char c){
        if(now-outbuf==OUT_BUF){
            fwrite(outbuf,1,OUT_BUF,stdout);
            now=outbuf;
        }
        *now++=c;
    }
    inline void write(int x){
        if(x==0){
            pc('0');
            return ;
        }
        if(x<0){
            x=-x;
            pc('-');
        }
        char s[25];
        int len=0;
        while(x){
            s[len++]=x%10+'0';
            x/=10;
        }
        while(len--) pc(s[len]);
    }
    inline void flush(){
        fwrite(outbuf,1,now-outbuf,stdout);
        now=outbuf;
    }
}
using namespace fastIO;
const int N=5e5+5;
int n,m,a[N],ans;
inline int check(int x){
    int num=0;
    int mm=m;
    for(int i=x;i>=1;i--){
        if(mm>=a[x]-a[i]){
            mm-=a[x]-a[i];
            num++;
        }else{
            return num;
        }
    }
    return num;
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        int j=i+1;
        while(a[i]==a[j]) j++;
        i=j-1;
        ans=max(ans,check(i));
    }
    write(ans);
    flush();
    return 0;
}
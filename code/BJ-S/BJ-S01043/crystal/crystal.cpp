#include <stdio.h>
#include <algorithm>
using namespace std;
#define MAXN 500005
#define int long long
int n,m,a[MAXN],pos=1,currv,ans;
int read(){
    int c=getchar(),x=0,tm=1;
    while(c!='-'&&(c<'0'||c>'9')) c=getchar();
    if(c=='-'){
        tm=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x*=10;
        x+=c-'0';
        c=getchar();
    }
    return x*tm;
}
int buff[200],tp;

void write(int x){
    if(x==0){
        putchar('0');
        return;
    }
    if(x<0){
        putchar('-');
        x=-x;
    }
    tp=0;
    while(x){
        buff[++tp]=x%10;
        x/=10;
    }
    do{
        putchar(buff[tp]+'0');
    }while(--tp);
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++){
        currv+=(i-pos)*(a[i]-a[i-1]);
        while(currv>m){
            currv-=(a[i]-a[pos]);
            pos++;
        }
        ans=max(ans,i-pos+1);
    }
    write(ans);
    return 0;
}

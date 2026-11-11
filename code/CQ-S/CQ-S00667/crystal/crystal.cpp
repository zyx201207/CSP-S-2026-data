#include<bits/stdc++.h>
#define int long long
using namespace std;

int read(){
    int x=0,f=1,ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}
int ___[40];
void write(int x){
    if(x<0){
        putchar('-'),x=-x;
    }
    if(x==0){
        putchar('0');
        return;
    }
    int tot=0;
    while(x){
        ___[++tot]=x%10+'0';
        x/=10;
    }
    while(tot){
        putchar(___[tot--]);
    }
}

const int N=5e5+20;

int n,a[N],m,sum[N];

int ask(int l,int r){
    return (r-l+1)*a[r]-(sum[r]-sum[l-1]);
}
signed main(){
    // freopen("crystal4.in","r",stdin);
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
    }
    int ans=0;
    for(int i=n,j=n;i>=1;i--){
        while(1){
            if(j==1)break;
            // cerr<<j-1<<" "<<i<<" "<<ask(j-1,i)<<"\n";
            if(ask(j-1,i)>m)break;
            j--;
        }
        ans=max(ans,i-j+1);
    }
    write(ans);
    return 0;
}
/*
3845
315275

*/
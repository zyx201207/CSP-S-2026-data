#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,a[N],b[N],bs[N],ans=1,p,sum;
inline int read(){
    char ch=0;
    int x=0,w=1;
    while(ch<'0'||ch>'9'){
        if(ch=='-')
            w=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*w;
}
inline void write(int x){
    if(x>9)
        write(x/10);
    putchar(x%10+'0');
}
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    sort(a+1,a+n+1);
    for(int i=2;i<=n;i++){
        b[i]=a[i]-a[i-1];
        bs[i]=bs[i-1]+b[i];
    }
    p=0;
    for(int i=2;i<=n;i++){
        while(1){
            if(sum+(p+1)*b[i+p]>m||i+p>n)
                break;
            sum+=(p+1)*b[i+p];
            p++;
        }
        ans=max(ans,p);
        sum-=bs[i+p-1]-bs[i-1];
        if(p)
			p--;
    }
    write(ans+1);
}

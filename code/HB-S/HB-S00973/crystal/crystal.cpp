#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int a[N],s[N],ans,n,m;

int work(int p){
    int l=1,r=p,mid;
    while(l<r){
        mid=l+r>>1;
        if(a[p]*(p-mid+1)-(s[p]-s[mid-1])<=m)r=mid;
        else l=mid+1;
    }
    return p-l+1;
}

signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    for(int i=1;i<=n;++i){
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;++i){
        ans=max(ans,work(i));
    }
    print(ans);putchar('\n');
    return 0;
}
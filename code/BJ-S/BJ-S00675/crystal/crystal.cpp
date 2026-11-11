#include<bits/stdc++.h>
#define int long long
using namespace std;

inline int read(){
    int n=0,f=1;
    char c=getchar();
    while(c<'0'||'9'<c){
        if(c=='-')f=-1;
        c=getchar();
    }
    while('0'<=c&&c<='9'){
        n=(n<<3)+(n<<1)+(c^48);
        c=getchar();
    }
    return n*f;
}

inline void write(int x){
    if(x<0){
        x=-x;
        putchar('-');
    }
    if(x>9)write(x/10);
    putchar(x%10^48);
    return;
}

int n,m,ans;
int a[500005];

signed main(){
    freopen("crystal.in","r",stdin);
    //freopen("crystal1.in","r",stdin);
    freopen("crystal.out","w",stdout);
    n=read();
    m=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1);
    int sum=0;
    for(int l=1,r=1;r<=n;++r){
        sum+=(r-l)*(a[r]-a[r-1]);
        while(sum>m){
            sum-=a[r]-a[l++];
        }
        ans=max(ans,r-l+1);
    }
    write(ans);putchar('\n');
    return 0;
}
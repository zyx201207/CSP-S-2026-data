#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn=2e5+100;
int a[maxn],n,sum;
char c[10000000+10];

int read() {
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

void write(int x) {
    if(x<0) {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

int cnt;
int pre[maxn];

signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    n=read();

    for(int i=1;i<=n;i++) {
        int x; x=read();
        char m; cin>>m;
        for(int j=cnt+1;j<=cnt+x;j++) {
            c[j]=m;
        }
        cnt=cnt+x;
    }

    int ans=0;

    for(int i=1;i<=cnt/2;i++) {
        if(c[i]!=c[cnt+i-1]) ans++;
    }

    cout<<ans;

    return 0;
}

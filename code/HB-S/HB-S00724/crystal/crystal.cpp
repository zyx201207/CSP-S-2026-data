#include<bits/stdc++.h>
using namespace std;

#define int long long

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

int write(int x) {
    if(x<0) {
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+'0');
}

const int maxn=5e5+100;

int n,m;
int a[maxn],sum[maxn],ans[maxn];
int cnt;

int check(int i,int mid) {
    if((mid-1)*a[i]-(sum[i-1]-sum[i-mid])<=m) return 1;
    else return 0;
}

signed main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();

    for(int i=1;i<=n;i++) {
        a[i]=read();
    }

    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];

    for(int i=1;i<=n;i++) {
        int l=0,r=i;
        while(l<r) {
            int mid=l+r+1>>1;
            if(check(i,mid)) l=mid;
            else r=mid-1;
        }
        ans[i]=l;
    }

    for(int i=1;i<=n;i++) cnt=max(cnt,ans[i]);

    write(cnt);

    //cout<<((cnt-1)*a[cnt]-sum[cnt-1])<<"\n";
    //cout<<sum[cnt-1]<<' '<<(cnt-1)*a[cnt];

    return 0;
}

#include<bits/stdc++.h>
using namespace std;

#define int long long

const int maxn=2e5+100;

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

int n,m;
int a[maxn],f[40];
int ans[40];
priority_queue<int> q;

signed main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    n=read(),m=read();

    for(int i=1;i<=n;i++) {
        a[i]=read();
        for(int j=35;j>=0;j--) {
            if(((long long)1<<j)&a[i]) f[j]++;
        }
    }

    for(int i=1;i<=n;i++) {
        for(int j=35;j>=0;j--) {
            if(((long long)1<<j)&a[i]) {
                if(f[j]<m) a[i]-=((long long)1<<j);
            }
        }
        q.push(a[i]);
    }

    while((!q.empty())&&(m>0)) {
        int x=q.top();
        q.pop();
        int o=0;
        for(int i=35;i>=0;i--) {
            if(((long long)1<<i)&x) {
                //cout<<x<<' '<<i<<"\n";
                if(o==1) {ans[i]++;}
                else if(o==-1) {if(ans[i]>=2) x-=((long long)1<<i);}
                else if(o==0){
                    if(ans[i]>=2) {
                        o=-1;
                        x-=((long long)1<<i);
                    }else {
                        o=1;
                        ans[i]++;
                        //cout<<x<<' '<<99<<' ';
                    }
                }
            }
        }
        if(o==-1) q.push(x);
        if(o) m--;
    }

    int sum=0;

    for(int i=35;i>=0;i--) {
        if(ans[i]>=m) sum+=((long long)1<<i);
        //cout<<i<<' '<<ans[i]<<"\n";
    }

    cout<<sum;

    return 0;
}

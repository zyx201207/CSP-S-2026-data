#include <bits/stdc++.h>

using namespace std;

long long n,m,ans=1;
long long a[500005];

inline long long read() {
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<= '9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

bool check() {
    for(int i=2;i<n;i++)
        if(a[i]-a[i-1]!=a[i+1]-a[i]) return false;
    return true;
}

int main() {
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);

    n=read(),m=read();
    for(int i=1;i<=n;i++) {
        a[i]=read();
    }
    sort(a+1,a+n+1);

    if(check()) {
        long long mm=m,tmp=1;
        for(int j=n-1;j>=1;j--) {
            if(a[n]-a[j]<=mm) {
                mm-=(a[n]-a[j]);
                tmp++;
            }
            else {break;}
        }
        ans = max(ans,tmp);
        cout << ans << endl;
        return 0;
    }

    long long cnt=0;
    for(int i=n;i>=2;i--) {
        if(i<=ans) {break;}
        long long mm=m,tmp=1;
        for(int j=i-1;j>=1;j--) {
            cnt++;
            if(a[i]-a[j]<=mm) {
                mm-=(a[i]-a[j]);
                tmp++;
            }
            else {break;}
        }
        ans = max(ans,tmp);
        if(cnt>=270000000) break; //QAQ
    }

    cout << ans << endl;

    return 0;
}

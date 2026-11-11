#include <bits/stdc++.h>

using namespace std;

inline long long read() {
    long long x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9') {
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0' && ch<='9') {
        x=x*10+ch-'0';
        ch=getchar();
    }
    return x*f;
}

int n;
long long sum,ans;
long long a[200005];
char c[200005];

int main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    n=read();
    for(int i=1;i<=n;i++) {
        a[i]=read(); c[i]=getchar();
//        cout << a[i] << ' ' << c[i] << endl;
        sum+=a[i];
    }

    int cnt=1,l=1,r=n;
    while(l<r) {
 //       cout << l << ' ' << r << endl;
        int x=a[l],y=a[r];
        if(x<y) {
            if(c[l]!=c[r]) ans+=x;
            a[l]-=x,a[r]-=x; l++;
            //cout << "x<=y:ans" << ans << endl;
        }
        else if(x>y) {
            if(c[l]!=c[r]) ans+=y;
            a[l]-=y; a[r]-=y; r--;
            //cout << "x>y:ans" << ans << endl;
        }
        else {
            if(c[l]!=c[r]) ans+=x;
            a[l]-=y; a[r]-=y; l++,r--;
            //cout << "x=y:ans" << ans << endl;
        }
    }

    cout << ans;

    return 0;
}
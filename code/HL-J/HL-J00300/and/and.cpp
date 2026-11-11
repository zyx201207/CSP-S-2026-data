#include <iostream>
using namespace std;
int a[1000005];
int b[1000005];
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++) cin >> a[i];
    int maxa=0,s=0;
    for(int i=1;i<=n;i++){
        if(m==2) {
            for(int j=i+1;j<=n;j++) {
                s=a[i]&a[j];
                if(s>maxa) maxa=s;
            }
        } else if(m==1) {
            s=a[i]&a[i];
            if(s>maxa) maxa=s;
        } else if(m==n) {
            m=a[1];
            maxa&=a[i];
        }
    }
    cout << maxa;
    return 0;
}


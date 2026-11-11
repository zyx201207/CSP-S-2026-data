#include<bits/stdc++.h>
using namespace std;
int a[200005],f[200005];
int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    cin >> a[1];
    int maxa=0,k=a[1];
    for(int i=2;i<=n;i++) {
        cin >> a[i];
        f[i]=a[i];
        maxa=max(maxa,a[i]);
        k=k&a[i];
    }
    if(m==1) cout << maxa;
    if(m==n) cout << k;
    if(m==2){
        int ans1=a[1]&a[2];
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<=n;j++) {
                ans1=max(ans1,a[i]&a[j]);
            }
        }
        cout << ans1;
    }
    return 0;
}
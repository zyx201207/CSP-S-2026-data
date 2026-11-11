#include <bits/stdc++.h>
using namespace std;
int main () {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>>n>>m;
    int a[n+1];
    int max=0;
    for (int i=1;i<=n;i++) {
        cin>>a[i];
    }
    for (int i=1;i<=n;i++) {
        int s=0;
        for (int j=i;j<=n;j++) {
            if (a[i]>a[j]) {
                s=a[i]&a[j];
            }
            else {
                s=a[j]&a[i];
            }
            if (s>max) {
                max=s;
                cout<<max<<endl;
            }
        }
    }
    cout<<max;
    return 0;
}

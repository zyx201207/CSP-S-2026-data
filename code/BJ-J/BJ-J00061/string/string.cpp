#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    int a[n+5],m = 0;
    char c[n+5];
    for(int i = 1;i<=n;i++){
        cin >> a[i] >> c[i];
        m+=a[i];
    }
    int ar[m+5];
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=a[i];j++){
            ar[++cnt] = c[i];
        }
    }
    int diff = 0;
    for(int i = 1;i<=m;i++){
        if(ar[i]!=ar[m+1-i]) diff++;
    }
    diff = diff/2;
    cout << diff;
    return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5;
int n;
int a[N];
char c[N];
char zf[N*500];
signed main() {
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>c[i];
    }
    int zzz=1;
    int L=0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++){
            zf[zzz++]=c[i];
        }
        L+=a[i];
    }
    int ans=0;
    for(int i = 1; i <= (L+1)/2; i++){
        if(zf[i]!=zf[L-i+1]) {
            ans++;
        }
    }
    cout<<ans;
    return 0;
}

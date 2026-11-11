#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+1000;
int n,a[N],f[N],cnt;char c[N];
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    int l=1,r=n;
    while(l<r){
        if(a[l]-f[l]>a[r]-f[r]){
            if(c[l]!=c[r]){
                cnt+=(a[r]-f[r]);
            }
            f[l]+=(a[r]-f[r]);
            f[r]+=(a[r]-f[r]);
            r--;
        }else{
            if(c[l]!=c[r]){
                cnt+=(a[l]-f[l]);
            }
            f[r]+=(a[l]-f[l]);
            f[l]+=(a[l]-f[l]);
            l++;
        }
    }
    cout << cnt;
    return 0;
}


#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int a[maxn],sum[maxn];
int n,m;
signed main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            sum[i]+=a[i]-a[j];
        }
        if(sum[i]>m){
            cout << i-1;
            return 0;
        }
    }
    if(sum[n]<m) {
        cout << n;
        return 0;
    }
    cout << 0;
    return 0;
}

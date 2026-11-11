#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,a[1000005],maxn=0;
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >>m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
        for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            int ans=a[i]&a[j];
            maxn=max(maxn,ans);
            }
    }
    cout << maxn;
}

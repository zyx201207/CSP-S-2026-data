#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxn = 0;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            maxn = max(maxn,a[i] * a[i+1]);
        }
    }
    cout << maxn;
    return 0;
}

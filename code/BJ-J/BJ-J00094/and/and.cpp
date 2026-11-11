#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 2e5+10;
ll n,m,a[N],d[N];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++){
        cin >> a[i];
        d[0]=a[i];
        for (int j = m;j >= 1;j--){
            d[j]=max(d[j],(d[j-1]&a[i]));
        }
    }
    cout << d[m]<<"\n";
    return 0;
}

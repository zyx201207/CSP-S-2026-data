#include <bits/stdc++.h>
using namespace std;
unsigned long long n,m;
long long a[500010];
long long cnt;
long long tot;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        tot+=a[i];
        if(m<tot||i==n){
            cout << i ;
            return 0;
        }
    }
    cout << 1;
    return 0;
}

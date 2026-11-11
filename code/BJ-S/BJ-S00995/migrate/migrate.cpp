#include<bits/stdc++.h>
using namespace std;

long long a[2000006];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    long long c,t;
    cin >> c >> t;
    for(int i=1;i<=t;i++){
        long long n,m;
        cin >> n >> m;
        for(int j=1;j<=n;j++){
            cin >> a[j];
        }
        cout << n/2 << endl;
    }
    return 0;
}

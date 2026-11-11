#include <bits/stdc++.h>
using namespace std;

int c,t,n,d;

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);

    cin >> c >> t;
    for(int i=1;i<=t;i++){
        int z[2000005]={0};
        int h[2000005]={0};
        cin >> n >> d;
        for(int j=1;j<=n;j++){
            cin >> z[j];
            h[i] = h[i-1]+z[j];
        }
        int sum = 0;
        for(int j=3;j<=n;j++){
            sum += h[j];
        }
        cout << sum/2 << endl;
    }

    return 0;
}

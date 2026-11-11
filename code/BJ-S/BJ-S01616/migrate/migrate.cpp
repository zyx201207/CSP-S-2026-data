#include <bits/stdc++.h>
using namespace std;
long long C,T;
const int MMax = 2e6+9;
long long a[MMax];

int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> C >> T;
    for(int i=1;i<=T;i++){
        long long N,D;
        cin >> N >>D;
        memset(a,0,sizeof(a));
        for(int j=1;j<=N;j++){
            cin >> a[j];
        }
        long long D_hat = a[2] - a[1];
        if(D>3*D_hat&&D<2*D_hat){
            cout << 0 <<'\n';
        }
        else{
            cout << max(N-3,0)<< '\n';
        }

    }

    return 0;
}

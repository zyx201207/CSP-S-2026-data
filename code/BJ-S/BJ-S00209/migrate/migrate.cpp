#include <bits/stdc++.h>

using namespace std;

int c, t;
int n, d;
int x[2000005];

int a(){
    int d = x[2]-x[1];
    for (int i=2; i<n; i++){
        if (x[i+1]-x[i] != d){
            return -1;
        }
    }
    return abs(d);
}

int main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin>>c>>t;
    while (t--){
        cin>>n>>d;
        if (n == 1){
            cout<<0<<endl;
            continue ;
        }
        for (int i=1; i<=n; i++){
            cin>>x[i];
        }
        if (a() != -1){
            int gc = a();
            if (d < gc  &&  gc <= 2*d){
                cout<<n-3<<endl;
                continue ;
            }
            cout<<0<<endl;
            continue ;
        }
        cout<<0<<endl;
    }

    return 0;
}

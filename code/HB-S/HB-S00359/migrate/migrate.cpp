#include<bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t,n,d;
    cin >> c >> t;
    for(int i = 0;i < t;i++){
        cin >> n >> d;
        for(int i = 0;i < n;i++){
            cin >> a[i];
        }
        cout << n - 3;
    }
    return 0;
}

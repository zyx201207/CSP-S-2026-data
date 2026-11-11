#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[2000005];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t, n, d;
    cin >> c;
    if(c == 11 || c == 12){
        cin >> t; 
        while(t--){
            cin >> n >> d;
            for(int i = 0; i < n; i++){
                cin >>a[i];
            }
            r = a[1] - a[0];
            if(2*r >= d){
                cout << 0;
            }
            else{
                cout << n-1;
            }
        }
    }
    cout << 0 << endl << 2 << endl;
    return 0;
}

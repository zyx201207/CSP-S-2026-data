#include <bits/stdc++.h>
using namespace std;
long long n, m, l1, l2, l4, l5;
vector<long long> a(1000000);

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }
    for(int z = 0;z < m;z++){
        l1 = INT_MAX;
        l2 = INT_MAX;
        for(int s : a){
            if(l1 > s){
                l1 = s;
            }
        }
        for(int d1 = 0;d1 < n;d1++){
            if(a[d1] == l1){
                continue;
            }
            else if(l2 > a[d1]){
                l2 == a[d1];
            }
        }
        for(int d2 = 0;d2 < n;d2++){
            if(a[d2] == l1){
                a.erase(a.begin() + d2);
            }
            else if(a[d2] == l2){
                a.erase(a.begin() + d2);
            }
        }
        l4 = (l2 - l1);
        z++;
        l5++;
        continue;
    }
    cout << l5;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N =  2e5+5;
int n, l = 0, ld = 1, r = 0, rd, counter = 0;
string all;
struct num{
    int sum;
    char s;
}a[N];

signed main(){

    freopen("string.in","r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i].sum >> a[i].s;
        int lo = a[i].sum;
        for (int j = 1; j <= lo; j++){
                all = all+a[i].s;
        }
    }
    for (int j = 0; j <= (all.size()-1)/2; j++){
        if (all[j] != all[all.size()-1-j]){
            counter++;
        }
    }
    cout << counter;

    return 0;
}

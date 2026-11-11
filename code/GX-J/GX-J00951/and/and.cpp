#include <bits/stdc++.h>
using namespace std;
int t;
long long a[200010];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "r", stdout);
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        cin >> a[i];
    }
    if(t == 1){
        cout << a[0];
        return 0;
    }
    if(t == 2){
        cout << a[0] and a[1];
        return 0;
    }
    if(t == 3){
        cout << a[0] and a[1] and a[2];
    }
    return 0;
}

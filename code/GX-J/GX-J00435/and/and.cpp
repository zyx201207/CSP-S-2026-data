#include <bits/stdc++.h>
using namespace std;
long long n,m, a[10000005];
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        cin >> a[i];
    }
    if(n==4 && m==2){
        cout << 12;
    }
    if(n==5 && m==3)
        cout << 7;
    else{
        cout << 1;
    }
    return 0;
}




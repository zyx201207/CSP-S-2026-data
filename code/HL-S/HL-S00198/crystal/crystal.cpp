#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    int ce;
    int a, b;
    cin >> a >>b;
    ce = b - a;
    cout << m/ce+1;
    
    return 0;
}
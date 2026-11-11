#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m,a[200000];
    cin >> n >> m;
    for (int i = 1;i <= n;i ++)
    {
        cin >> a[i];
    }
    cout << a[n];
    return 0;
}

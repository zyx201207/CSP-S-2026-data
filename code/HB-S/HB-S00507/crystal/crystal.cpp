#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    int n;
    int b;
    long long m;
    cin >> n >> m;
    long long a[10005];
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    long long c[10005];
    for(int i=1;i<=n;i++){
        c[i] = a[i+1] - a[i];
        if(c[i] > m/2){
             b = i;
            break;
        }
    }
    cout << b;
    return 0;
}


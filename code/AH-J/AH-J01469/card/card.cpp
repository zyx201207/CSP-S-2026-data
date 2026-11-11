#include <bits/stdc++.h>
using namespace std;
int main (){
    freopen ("and.in","r",stdin);
    freopen ("and.out","w",stdout);
    int m,n;
    cin >> n >> m;
    int c[n];
    for (int i=0;i<n;i++){
        cin >> c[i];
    }
    for(int i=0;i<n;i++){
        cout << c[i];
    }
    return 0;
}

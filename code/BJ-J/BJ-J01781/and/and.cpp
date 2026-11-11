#include <iostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    int a[n+5];
    for (int i=0;i<n;i++) cin >> a[i];
    sort(a[0],a[n-1]);
    int b=a[0];
    for(int i=1;i<m;i++){
        b = b & a[i];
    }
    cout << b;
    return 0;
}
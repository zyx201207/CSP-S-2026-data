#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int a[N+5],zdy[N+5];
int m,n;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }
    sort (a+1,a+1+n);
    zdy[1] = a[n];
    for(int i=2;i<=n;i++){
        zdy[i] = zdy[i-1] & a[n-i+1];
    }
    if(m==1){
        cout << a[n];
    }
    if(m==n){
        cout << zdy[n];
    }

    return 0;
}

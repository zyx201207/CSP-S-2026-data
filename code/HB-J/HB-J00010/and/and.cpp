#include <bits/stdc++.h>
using namespace std;
char a[200010];
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin>> n,m;
    for(int i = 0; i <= n ; i++){
        cin >> a[i];
        if(i == n){
            cout << a[i];
        }
    }
    return 0;
}

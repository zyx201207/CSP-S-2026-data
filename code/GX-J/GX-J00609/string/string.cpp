#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n;
    cin >> n;
    int a[100005];
    char c[100005];
    for(int i=1;i<=n;i++){
        cin >> a[i] >> c[i];
    }
    if(n==1){
        cout << "0";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=a[i];j++){
            cout << c[i];
        }
    }
    return 0;
}

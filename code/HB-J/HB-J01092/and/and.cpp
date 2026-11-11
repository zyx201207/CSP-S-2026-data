#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    int n,m;
    int a[10005];
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }

    int num;
    if(m == 1){
        num = a[1];
        for(int i = 1;i <= n;i++){
            if(a[i+1]>a[i]){
                num = a[i+1];
            }
        }
        cout << num;
    }
    if(m == n){
        for(int i = 1;i <= n;i++){
        }
    }

    return 0;
}

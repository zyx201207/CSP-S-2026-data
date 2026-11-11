#include<bits/stdc++.h>
using namespace std;
int n,m,a;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= m;j++){
            cin >> a;
        }
    }
    if(n % a == 0){
        cout << n/a;
    }else{
        cout << n%a;
    }
    return 0;
}

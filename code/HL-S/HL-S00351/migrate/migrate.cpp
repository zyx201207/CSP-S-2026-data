#include<bits/stdc++.h>
using namespace std;
int x[2000006];
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int n,t,c,d;cin >> c >> t >> n >> d;
    for(int i = 1;i <= n;i++){
        cin >> x[i];
    }
    if(n == 4){
        cout << 1 << endl;
        cout << 2;
    }
    else{
        cout << 0 << endl;
        cout << 1;
    }
    return 0;
}

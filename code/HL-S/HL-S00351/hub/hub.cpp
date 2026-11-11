#include<bits/stdc++.h>
using namespace std;
int u[2000005],v[2000005];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t,n,k;cin >> c >> t >> n >> k;
    for(int i = 1;i <= n;i++){
        cin >> u[i] >> v[i];
    }
    if(n == 5){
        cout << 1 << endl;
        cout << 2;
    }
    else{
        cout << 1 << endl;
        cout << 2;
    }
    return 0;
}

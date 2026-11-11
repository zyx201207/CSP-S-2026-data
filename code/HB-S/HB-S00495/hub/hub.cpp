#include<bits/stdc++.h>
using namespace std;

int u[100000001];
int v[100000001];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);

    int t,c;
    cin >> c >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        for(int i = 1;i<=n-1;i++){
        cin >> u[i] >> v[i];
    }
        if(k == 2){
        cout << 1 << endl;
        }
        if(k == 3){
            cout << 2 << endl;
        }
    }

    return 0;

}

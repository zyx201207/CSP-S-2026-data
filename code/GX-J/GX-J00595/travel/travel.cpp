#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel","r",stdin);
    freopen("travel","w",stdout);
    int R[100010],X[100010];
    int n,m;
    cin >> n >> m;
    for(int i=1; i<=n; i++){
        for(int j=1; j<=m; j++){
            cin >> R[i] >> X[i];
            if(R[i]==X[i]){
                cout << 1;
            }
            else if(R[i]!=X[i]){
                cout << 0;
            }
        }
    }
    return 0;
}

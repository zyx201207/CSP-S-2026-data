#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cin>> n >> m;
    int a[200005];
    int suma[200005];
    for(int i = 1;i <= n;i++){
        cin >> a[i];
    }
    for(int i = 1;i <= n;i++){
        int v[200005]; //
        for(int j = 1;j <= 200004;j++){
            v[j] = 0;
        }
        int lenv = 1;
        for(int j = i;j <= n;j++){
            int c = 0;
            v[lenv] = a[j];
            for(int z = 1;z <= 200004;z++){
                if(v[z] == a[j] && z != lenv){
                    c = z;
                }
            }
            for(int z = 1; z <= c;z++){
                v[z] = v[z + c +1];
            }
            lenv = lenv + 1 - c;
        }
        for(int j = 1;j <= lenv;j++){
            suma[v[j]] += 1;
        }
    }
    for(int i = 1;i <= m;i++){
        cout << suma[i] << " ";
    }
}

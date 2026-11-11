#include<bits/stdc++.h>
using namespace std;

const int N = 5e5+5, M = 3e5+5;;
int n, m;
int a[N], b[N],c[N];

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            c[j] = a[j];
            for(int k = i; k < j; k++){
                if(c[j] == c[k]){
                    for(int x = k; x < j; x++){
                        c[x] = 0;
                    }
                    break;
                }
            }
        }
        for(int k = i; k <= n; k++){
            if(c[k] != 0){
                b[c[k]]++;
                //cout << c[k] << " ";
            }
        }
        //cout << '\n';
    }
    for(int i = 1; i <= m; i++){
        cout << b[i] << " ";
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N = 6e5+5;
int n, m, counter = 0, a[N], b[N], c[N];
string s;

int main(){

    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++){
        counter = 0;
        //s = "";
        for (int j = 1; j <= N; j++){
            b[j] = 0;
        }
        for (int j = i; j <= n; j++){
            if (b[a[j]] >= 1){
                b[a[j]] = 1;
                for (int k = 1; k <= n; k++){
                    if (a[k] == a[j]){
                        for (int h = k+1; h <= n; h++){
                            b[h] = 0;
                        }
                    }
                }
            }
            else{
                b[a[j]]++;
            }
        }
        for (int j = 1; j <= n; j++){
            c[j] += b[j];
        }
    }
    for (int i = 1; i <= m; i++){
        cout << c[i] << " ";
    }

    return 0;
}

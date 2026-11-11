#include <bits/stdc++.h>
using namespace std;

int b[500010], a[500010];
bool c[500010];
int d[300010];


int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    int n, m, cur = 0; cin >> n >> m;

    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int stt = 1; stt <= n; stt++){
        for(int i = stt; i <= n; i++){
            bool fg = 0;
            for(int j = stt; j < i; j++){
                //cout << j << " " << i << " " << a[j] << " " << a[i] << "\n\n";
                if(a[j] == a[i]){
                    fg = 1;
                }
                if(fg){
                    b[j] = 1;
                }

            }
        }
        for(int i = stt; i <= n; i++){
            if(!b[i]){

                d[a[i]]++;
            }
            b[i] = 0;
        }
        /*cout << "\n1-1-1-1-1-1-1-1-1-1-1-1-1-1-1-\n\n";
        for(int i = stt; i <= n; i++){
            cout << a[i] << " ";
        }
        cout << "\n";
        for(int i = stt; i <= n; i++){
            cout << b[i] << " ";
        }
        cout << "\n---------------------\n";*/
    }



    for(int i = 1; i <= m; i++){
        cout << d[i] << " ";
    }
    cout << "\n";
    return 0;
}

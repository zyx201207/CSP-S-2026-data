#include <bits/stdc++.h>
using namespace std;

int main(){
    feopen("card.in", "r",stdin);
    feopen("card.out", "w",stdout);
    int n, m;
    cin >> n >> m;
    int a[n], b[n], s[m];
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = 1    ;
    }
    for(int i = 1; i <= m; i++){
        s[i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j++){
            int fuc = 0;
            while(fuc < n){
                if(a[j] == a[fuc]){
                    for(int k = j; k < fuc; k++){
                        b[k] = 0;
                    }
                }
                fuc++;
            }
            if(b[j] != 0) s[a[j]]++;
            for(int l = j; l <= n; l++) b[l] = 1;
        }

    }
    for(int i = 1; i <= m; i++){
        cout << s[i] << " ";
    }

    return 0;
}




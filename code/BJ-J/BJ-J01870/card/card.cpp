#include<bits/stdc++.h>
using namespace std;
int b[1000000], d[1000000];
int a[1000000], c[1000000], k = 0, m;
int main(){
    int n;
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(b[a[i]] >= 1){
            bool flag = 0;
            for(int j = 0; j < n; j++){
                if(c[j] == a[i]){
                    flag = 1;
                    k = j;
                }
                if(flag){
                    c[i] = 0;
                    b[a[i]] -= 1;
                }else{
                    d[c[j]] += 1;
                }
            }
            c[k] = a[i];
            k++;
            b[a[i]] = 1;
            d[c[i]] += 1;
        }
        else{
            c[k] = a[i];
            k++;
            b[a[i]] = 1;
        }
        for(int j = 0; j < k; j++){
            d[c[j]] += 1;
        }
    }
    for(int i = 1; i <= m; i++){
        cout << d[i] << " ";
    }
    return 0;
}

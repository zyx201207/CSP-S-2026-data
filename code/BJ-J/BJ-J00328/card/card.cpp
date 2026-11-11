#include <bits/stdc++.h>
using namespace std;
int a[500050],n,m;
int nu[400020];
bool v[400020];
int main(){
    freopen("card.in",'r',stdin);
    freopen("card.out",'w',stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        for(int j = i;j <= n;j++){
            if(v[a[j]]){
                for(int l = j-1;l >= i;l--){
                    v[a[l]] = 0;
                    if(a[l] == a[j]) break;
                }
            }
            v[a[j]] = 1;
        }
        for(int op = 1;op <= m;op++){
            if(v[op]){
                v[op] = 0;
                nu[op]++;
            }
            if(i == n && nu[op]) cout << nu[op] << " ";
        }
    }
    return 0;
}
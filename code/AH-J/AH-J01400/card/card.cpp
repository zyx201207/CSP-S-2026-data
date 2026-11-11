#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[500001],t[300001],b[300001];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = n; i >= 1; i--){
        memset(b, 0, sizeof(b));
        for(int j = n; j >= i; j--){
            if(b[a[j]] == 0){
                b[a[j]]++;
            } else{
                int x = a[j];
                for(int k = j + 1; k <= n; k++){
                    b[a[k]]--;
                    if(a[k] == x){
                        b[a[k]]++;
                        break;
                    }
                }
            }
        }
        for(int j = 1; j <= m; j++){
            if(b[j]){
                t[j]++;
            }
        }
    }
    for(int i = 1; i <= m; i++){
        cout << t[i] << " ";
    }
    return 0;
}

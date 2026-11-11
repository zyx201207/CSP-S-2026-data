#include<bits/stdc++.h>
using namespace std;

int n1, m;
int a[500005] = { };
int n[500005] = { };
int b[300005] = { };
int ans[300005] = { };

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n1 >> m;
    for(int i = 1; i <= n1; i++){
        cin >> a[i];
        //cout << a[i];
    }
    for(int i = 1; i <= n1; i++){
        long long cnt = 1;
        for(int j = i; j <= n1; j++){
            if(b[a[j]] == 0) {
                n[cnt] = a[j];
                b[a[j]] = cnt;
                cnt++;
                //if (i == 6) cout << cnt << " ";
            }else{
                cnt = b[a[j]] + 1;
                //if (i == 6) cout << cnt << " ";
            }
            //cout << endl << endl;
        }
        for(int k = 1; k <= cnt - 1; k++){
            //cout << n[k] << " ";
            ans[n[k]]++;
        }
        //cout << endl;
        memset(b, 0, sizeof(b));
        memset(n, 0, sizeof(n));
    }
    for(int i = 1; i <= m; i++){
        cout << ans[i] << " ";
    }
    return 0;
}
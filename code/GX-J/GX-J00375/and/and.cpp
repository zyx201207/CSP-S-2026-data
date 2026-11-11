#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,m;
    cin >> n >> m;
    int num[n];
    for(int i = 0;i < n;i++){
        cin >> num [i];
    }
    int ans[n][n];
    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            ans[i][j] = num[i] & num[j];
        }
    }

    int a = 0;

    for(int i = 0;i < n;i++){
        for(int j = 0;j < n;j++){
            if(i == j){
                continue;
            }
            if(ans[i][j] > a){
                a = ans[i][j];
            }
        }
    }
    cout << a << '\n';

    return 0;
}

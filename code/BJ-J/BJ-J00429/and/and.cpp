#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n, m;
    bool a[200005][31] = {};
    cin >> n >> m;
    for(int i = 1;i <= n;i++){
        int x;
        cin >> x;
        int y = 0;
        while(x){
            a[i][y] = x%2;
            x /= 2;
            y++;
        }
    }
    bool b[200005] = {}, ans[31] = {};
    for(int i = 30;i >= 0;i--){
        int num = 0;
        for(int j = 1;j <= n;j++){
            if(b[j]) continue;
            if(a[j][i]) num++;
        }
        if(num >= m){
            ans[i] = 1;
            for(int j = 1;j <= n;j++){
                if(b[j]) continue;
                if(!a[j][i]) b[j] = 1;
            }
        }
        else ans[i] = 0;
    }
    int an = 0, k = 1;
    for(int i = 0;i <= 30;i++){
        if(ans[i]) an += k;
        k *= 2;
    }
    cout << an;
    return 0;
}

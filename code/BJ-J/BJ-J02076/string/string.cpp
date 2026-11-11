#include <bits/stdc++.h>
using namespace std;
int n,a[200005],cnt;
string c,cc;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    if(n == 1){
        cout << 0;
        return 0;
    }
    for(int i = 1;i <= n;i++){
        cin >> a[i];
        cin >> cc;
        for(int j = 1;j <= a[i];j++){
            c += cc;
        }
    }
    if(c.size() == 2){
        if(c[0] == c[1]) cout << 0;
        else cout << 1;
        return 0;
    }
    bool f = 0;
    for(int i = 0;i < c.size();i++){
        if(c[i] == c[c.size() + 1 - i]) f = 1;
        else f = 0;
    }
    if(f == 1) cout << 0;


    int l = 1,r = c.size();
    for(int i = 1;i <= c.size();i++){
        if(c[r] != c[l]){
            c[r] = c[l];
            cnt ++;
        }
    }
    return 0;
}

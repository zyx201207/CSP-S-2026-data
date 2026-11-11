#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);

    int n,m;
    cin >> n >> m;
    int a[1000010];
    int a1[1000010] = {0};
    string b;
    for (int i=1; i<=n; i++){
        cin >> a[i];
    }

    for (int i=1; i<=n; i++){
        b.clear();
        for (int j=i; j<=n; j++){
            b += a[j]+'0';
            auto x = b.find(a[j] + '0');
            auto y = b.find(a[j] + '0' , x+1);
            if (x != string::npos && y != string::npos){
                b.erase(x, y-x);
            }
        }
        for (int j=0; j<b.size(); j++){
            a1[b[j]-'0'] ++;
        }
    }

    for (int i=1; i<=m; i++){
        cout << a1[i] << " ";
    }

    return 0;
}

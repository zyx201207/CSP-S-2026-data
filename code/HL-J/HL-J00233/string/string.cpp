#include <bits/stdc++.h>
using namespace std;
long long n;
char c[100][2];
int a;
string s;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 0;i < n;i++){
        cin >> c[i][0] >> c[i][1];
    }
    /*for (int i = 0;i < n;i++){
        cout << c[i][0] << c[i][1] << endl;
    }*/
    for (int i =1;i <= n;i++){
        for (int j = 0;j < c[i][0];j++){
            s = s + c[i][1];
        }
    }
    //cout << s;
    if (n % 2 == 1){
        for (int i = 0;i < n / 2 + 1;i++){
            if (s[i] != s[n - i]){
                a++;
            }
        }
    }
    else{
        for (int i = 0;i < n / 2;i++){
            if (s[i] != s[n - i]){
                a++;
            }
        }
    }
    cout << a;
    return 0;
}

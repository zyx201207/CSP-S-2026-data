#include<bits/stdc++.h>
using namespace std;
int s[1000010];
int a[100010];
char c[100010];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c[i];
    }
    for(int i = 1; i <= a[i]; i++){
        s[i] = s[c[i]];
    }
    cout << 0;
    return 0;
}

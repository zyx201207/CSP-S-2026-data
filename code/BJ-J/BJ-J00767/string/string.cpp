#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,a[3];
    char b,c;
    cin >> n;
    string s;
    if(n==1){
        cout << 0;
        return 0;
    }
    if(n==2){
        cin >>a[0] >> b >> a[1] >> c;
        if(b==c) cout << 0;
        else cout << min(a[0],a[1]);
    }
    return 0;
}

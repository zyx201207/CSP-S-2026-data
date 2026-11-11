#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string a;
    for(int i = 0; i < n; i++){
        int x;
        char b;
        cin >> x >> b;
        while(x--){
            a += b;
        }
    }
    //cout << a << endl;
    long long s = a.length();
    long long ans = 0;
    for(int i = 0; i <= s / 2; i++){
        if(a[i] != a[s - i - 1]){
            ans++;
            //cout << a[i] << " " << a[s - i - 1] << endl;
        }
    }
    cout << ans;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    string a;
    cin >> n;
    for(int i = 0;i < n;i++){
        long long m;
        string b;
        cin >> m >> b;
        for(long long j = 0;j < m;j++){
            a += b;
        }
    }
    long long cnt = 0, l = a.size();
    for(long long i = 0;i < l/2;i++){
        if(a[i] != a[l-i-1]){
            cnt++;
        }
    }
    cout << a << endl << cnt;
    return 0;
}
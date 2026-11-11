#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    long long cnt = 0;
    long long c = 0;
    string S = "1";
    for(int i = 1;i <= n;i++){
        long long x;
        char a;
        cin >> x >> a;
        for(long long j = 1;j <= x;j++){
            S += a;
        }
        cnt += x;
    }
    for(long long i = 1;i <= cnt / 2;i++){
        if(S[i] != S[cnt + 1 - i]){
            c += 1;
        }
    }
    cout << c;
    return 0;
}

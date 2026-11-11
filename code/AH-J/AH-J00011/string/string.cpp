#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;
    string s;
    char c[10005];
    long long a;
    long long b = 0;
    for(int i = 0;i < n;i ++){
        cin >> a;
        cin >> c[i];
        b += a;
        for(int j = 1;j <= a;j ++){
            s += c[i];
        }
    }
    int cnt = 0;
    long long k = b-1;
    if(b % 2 != 0){
        b = b/2+1;
    }
    else{
        b/=2;
    }
    for(int i = 0;i < b;i ++){
            while(k>=b){
                if(s[i] != s[k]) cnt ++;
                k--;
            }
        }
    cout << cnt;

    return 0;
}

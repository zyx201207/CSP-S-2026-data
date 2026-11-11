#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,cnt = 0;
    cin >> n;
    string s;
    for (int i=0; i<n; i++){
        int j;
        char c;
        cin >> j;
        cin >> c;
        for (int k=0; k<j; k++){
            s[cnt] = c;
            cnt++;
        }
    }
    int sum = 0;
    for (int a=0,b=cnt-1; a!=b; a++, b--){
        if (s[a]!=s[b]) sum++;
    }
    cout << sum;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","r",stdout);
    int n , sum = 0;
    cin >> n;
    int a[n];
    string b[n];
    string s;
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
        for(int j = 0; j < a[i]; i++){
            s += b[i];
            sum++;
        }
    }
    int all = 0;
    if(sum % 2 == 1){
        sum++;
        for(int i = 1; i < sum / 2; i++){
            if(s[i] != s[sum - i]){
                all++;
            }
        }
    }else{
        for(int i = 1; i < sum / 2; i++){
            if(s[i] != s[sum + 1 - i]){
                all++;
            }
        }
    }
    cout << all;
    return 0;
}

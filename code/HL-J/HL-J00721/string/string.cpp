#include <bits/stdc++.h>
using namespace std;

char arr[20000+10];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,idx = 1,cnt = 0;
    cin >> n;
    for (int i = 1 ; i <= n ; i++){
        int num;
        char c;
        cin >> num >> c;
        for (int j = 1 ; j <= num ; j++){
            arr[idx++] = c;
        }
        cnt += num;
    }
    int d = 0;
    for (int i = 1 ; i <= cnt/2 ; i++){
        if (arr[i] != arr[cnt - i+1]){
            d++;
        }
    }
    cout << d;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long long n, a[1000001];
char b[1000001];
long long sum, l, len;
string str;
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;
    for (long long i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    for (long long i = 0; i < n; i++){
        len += a[i];
    }
    if (len % 2 == 0){
        l = len / 2;
    } else{
        l = len / 2 + 1;
    }

    for (long long i = 0; i < n; i++){
        for (long long j = 0; j < a[i]; j++){
                str += b[i];
        }
    }
    for (long long i = 0; i < l; i++){
        if (str[i] != str[len - i - 1]){
            sum++;
        }
    }
    cout << sum << endl;

    fclose(stdin);
    fclose(stdout);
    return 0;
}

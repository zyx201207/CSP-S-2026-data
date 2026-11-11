#include<algorithm>
#include<iostream>
using namespace std;
long long c[200005], n, cn, cs, d, t, s;
char a[200005];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> c[i] >> a[i];
        cn += c[i];
    }
    for(int i = 1; i <= n; i++){
        d = cn / 2;
        if(cs + c[i] > d){
            for(int j = n; j >= i + 1; j--){
                a[j + 1] = a[j];
                c[j + 1] = c[j];
            }
            a[i + 1] = a[i];
            if(cn % 2 != 0) c[i]--;
            c[i + 1] = c[i] - d + cs;
            c[i] = d - cs;
            break;
        }
        cs += c[i];
    }
    if((n + 1) % 2 == 0){
        for(int i = (n + 1) / 2, j = n + 2 - i; i >= 1; i--){
            if(a[i] != a[j]){
                s += min(c[i], c[j]);
            }else{
                s += abs(c[i] - c[j]);
            }
        }
    }else{
        for(int i = n / 2, j = n + 3 - i; i >= 1; i--){
            if(a[i] != a[j]){
                s += min(c[i], c[j]);
            }else{
                s += abs(c[i] - c[j]);
            }
        }
    }
    cout << s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

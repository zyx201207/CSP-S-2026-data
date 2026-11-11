#include<bits/stdc++.h>
using namespace std;
long long n, a[200005], ch;
char c[200005];
int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> c[i];
    long long l = 0, r = n - 1;
    while(l < r){
        if(c[l] != c[r])
            ch += min(a[l], a[r]);
        if(a[l] == a[r])
            l++, r--;
        else if(a[l] > a[r])
            a[l] -= a[r], r--;
        else
            a[r] -= a[l], l++;
    }
    cout << ch;
    return 0;
}

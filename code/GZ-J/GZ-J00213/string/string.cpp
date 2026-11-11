//GZ-J00213遵义市第四中学周高逸

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, a[200005], s[200005], l=0, u=0;
char ch[200005];

char f(ll x){
    for(ll i=0; i<n; i++){
        if(s[i]<x && s[i+1]>=x) return ch[i+1];
    }
}

int main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(ll i=1; i<=n; ++i){
        cin >> a[i] >> ch[i];
        l += a[i];
        s[i] = s[i-1] + a[i];
    }

    for(ll i=1; i<=l/2+1; ++i){
        if(f(i) != f(l-i+1)) u++;
    }
    cout << u;

    return 0;
}

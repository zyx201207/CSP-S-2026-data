#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lx LONG_MAX
#define ln LONG_MIN
const int qq = 2e5+10;

ll s[qq],ans;
char c[qq];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n;cin >> n;
    for(int i = 1;i <= n;i ++){
        cin >> s[i] >> c[i];
    }
    for(int i = 1,j = n;;){
        if(i == j) break;
        int q = s[i];
        s[i] -= q;
        s[j] -= q;
        if(c[i] != c[j]) ans += q+s[j]*(s[j] < 0);
        if(s[j] < 0){
            s[i] -= s[j];
            j--;
        }else i ++;
    }cout << ans;
    return 0;
}

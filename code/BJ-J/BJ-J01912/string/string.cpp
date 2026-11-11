#include <bits/stdc++.h>
using namespace std;
long long a[200010];
string s[200010],t[8000010];
typedef long long love;
love x;
int main (){
    freopen("string.in","r",stdin);
   freopen("string.out","w",stdout);
    int n;
    cin >> n;
    love cnt = 1;
    love cccnt = 0;
    for (int i = 1; i <= n; i ++){
        cin >> a[i] >> s[i];
        x += a[i];
        while(a[i]> 0){
            t[cnt] = s[i];
            cnt++;
            a[i]--;
        }
    }
       love le = 1,ri = x;
        if(x%2 == 1){
            while(ri > x/2+1){
                if(t[ri] != t[le])cccnt++;
                ri--;
                le++;
            }
        }
        else{
            while(ri > x/2){
                if(t[ri] != t[le])cccnt++;
                ri--;
                le++;
            }
        }
        cout << cccnt;
    return 0;
}

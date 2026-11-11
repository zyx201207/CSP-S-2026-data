#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[200010];
char ch[200010];
signed main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> ch[i]; 
    }
    int x = a[1] , f = 0 , ans = 0;
    char c = ch[1];
    for(int xx = 1 , yy = n;xx <= yy;){
        if(f == 0){
            if(x > a[yy]){
                x -= a[yy];
                if(c != ch[yy]){
                    ans += a[yy];
                }
                yy--;
            }
            else if(x == a[yy]){
                x = a[xx + 1];
                if(c != ch[yy]){
                    ans += a[yy];
                    c = ch[xx + 1];
                }
                xx++;
                yy--;
            }
            else if(x < a[yy]){
                f = 1;
                if(c != ch[yy]){
                    ans += x;
                    c = ch[yy];
                }
                x = a[yy] - x;
                xx++;
            }
        }
        else{
            if(x > a[xx]){
                x -= a[xx];
                if(c != ch[xx]){
                    ans += a[xx];
                }
                xx++;
            }
            else if(x == a[xx]){
                f = 0;
                x = a[xx + 1];
                if(c != ch[xx]){
                    ans += a[xx];
                    c = ch[xx + 1];
                }
                xx++ , yy--;
            }
            else if(x < a[xx]){
                f = 0;
                if(c != ch[xx]){
                    ans += x;
                    c = ch[xx];
                }
                x = a[xx] - x;
                yy--;
            }
        }
        
    }
    cout << ans;
    return 0;
}
/*



6
1000000000 a
1000000000 a
1000000000 a
1000000000 b
1000000000 b
1000000000 b

*/
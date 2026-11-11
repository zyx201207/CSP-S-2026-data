#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
long long n;
struct node{
    long long num;
    char ch;
}a[N];
long long ans;


int main(){

    freopen("string.in","r".stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(int i = 1 ; i <= n ; i ++){
        cin >> a[i].num >> a[i].ch;
    }
    long long l = 1 , r = n;
    while(l < r){
        if(a[l].ch != a[r].ch){
            if(a[l].num > a[r].num){
                a[l].num -= a[r].num;
                ans += a[r].num;
                r--;
            }
            else if(a[l].num < a[r].num){
                a[r].num -= a[l].num;
                ans += a[l].num;
                l ++;
            }
            else if(a[l].num == a[r].num){
                ans += a[l].num;
                l ++;
                r --;
            }
        }
        else{
            if(a[l].num > a[r].num){
                a[l].num -= a[r].num;
                r--;
            }
            else if(a[l].num < a[r].num){
                a[r].num -= a[l].num;
                l ++;
            }
            else if(a[l].num == a[r].num){
                l ++;
                r --;
            }
        }
    }

    cout << ans << endl;

    return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
typedef long long i64;
constexpr int ms1 = 2e5 + 5;
using namespace std;

int n,l,r;
i64 ans = 0;

struct node{
    i64 a;
    char c;
}a[ms1];

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n;

    for(int i = 1;i <= n;i++){
        cin >> a[i].a >> a[i].c;
    }

    l = 1,r = n;
    while(l < r){
        if(a[l].c == a[r].c){
            if(a[l].a >= a[r].a){
                a[l].a -= a[r].a;
                r--;

                if(a[l].a <= 0){
                    l++;
                }
            }
            else if(a[l].a < a[r].a){
                a[r].a -= a[l].a;
                l++;

                if(a[r].a <= 0){
                    r--;
                }
            }
        }
        else{
            if(a[l].a >= a[r].a){
                ans += a[r].a;
                a[l].a -= a[r].a;
                r--;

                if(a[l].a <= 0){
                    l++;
                }
            }
            else if(a[l].a < a[r].a){
                ans += a[l].a;
                a[r].a -= a[l].a;
                l++;

                if(a[r].a <= 0){
                    r--;
                }
            }
        }
    }

    cout << ans;
    return 0;
}

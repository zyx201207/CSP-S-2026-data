#include<iostream>
using namespace std;
#define int long long

struct node{
    int c;
    char s;
};

node a[200005];

signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i){
        cin >> a[i].c >> a[i].s;
    }
    int r = 1, l = n, ans = 0;
    while(r <= l){
        if(a[r].s != a[l].s){
            if(a[r].c < a[l].c){
                ans += a[r].c;
                a[l].c -= a[r].c;
                r++;
            }
            else{
                if(a[r].c == a[l].c){
                    ans += a[r].c;
                    a[r].c = 0;
                    a[l].c = 0;
                    r++;
                    l--;
                }
                else{
                    if(a[r].c > a[l].c){
                        ans += a[l].c;
                        a[r].c -= a[l].c;
                        l--;
                    }
                }
            }
        }
        else{
            if(a[r].c < a[l].c){
                a[l].c -= a[r].c;
                r++;
            }
            else{
                if(a[r].c == a[l].c){
                    a[r].c = 0;
                    a[l].c = 0;
                    r++;
                    l--;
                }
                else{
                    if(a[r].c > a[l].c){
                        a[r].c -= a[l].c;
                        l--;
                    }
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
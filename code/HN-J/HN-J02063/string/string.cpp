#include <bits/stdc++.h>
#define ll long long
#define AC return 0
#define vei vector <int>
#define vel vector <ll>
#define pb push_back
#define db double

using namespace std;

struct p{
    int l;
    char c;
};

vector <p> s;

void in(){
    int n;
    cin >> n;
    for (int i = 1;i <= n;i++){
        int l;char c;
        cin >> l >> c;
        s.pb({l , c});
    }
    return ;
}

ll cnt;

int main(){
    freopen("string.in" , "r" , stdin);
    freopen("string.out" , "w" , stdout);
    in();
    for (int i = 0 , j = (int)s.size() - 1;i <= j;i++ , j--){
        if (i != j){
            if (s[i].c != s[j].c){
                cnt += max(s[i].l , s[j].l);
            }
        } else {
            if (s[i].l != s[j].l && abs(i - j) != 1){
                cnt += abs(s[i].l - s[j].l);
            }
        }
    }
    cout << cnt;
    AC;
}
/**


*/

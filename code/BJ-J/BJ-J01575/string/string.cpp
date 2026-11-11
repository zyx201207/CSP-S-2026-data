#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5+10;
int n,m,x,ans;
string s;
char c;
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> x >> c;
        for(int i = 1;i <= x;i++){
            s += c;
        }
        m += x;
    }
    int i = 0,j = m-1;
    while(i <= j){
        if(s[i] != s[j]){
            ans++;
        }
        i++,j--;
    }
    cout << ans;
    return 0;
}


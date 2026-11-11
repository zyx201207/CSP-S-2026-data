#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
long long n,a[N];
string ss[N];
char c;
int  cnt = 1,ans;
string s[N];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i] >> c;
        s[i] = c;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= a[i]; j++){
            ss[cnt] = s[i];
            cnt++;
        }
    }
    for(int i = 1; i <= n; i++){
        if(ss[i] != ss[n - i]) ans++;
    }
    cout << ans - 1;
    return 0;
}

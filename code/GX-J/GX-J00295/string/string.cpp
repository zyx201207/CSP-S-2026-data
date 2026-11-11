#include <bits/stdc++.h>
using namespace std;
string s;
long long a, n, ans=1, cnt=0;
char c;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a >> c;
        for (int i=1;i<=a;i++){
            s += c;
            ans += a;
        }
    }
    for (int i=1;i*i<=ans;i++){
        if(s[i]!=s[ans-i]){
          cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

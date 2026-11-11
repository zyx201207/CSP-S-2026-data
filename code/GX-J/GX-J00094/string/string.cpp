#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    long long n,ans = 0;
    string s;
    cin >> n;
    char k;
    for(long long i =1;i <= n;i++){
        long long a;
        char c;
        cin >> a >> c;
        while(a--){
            s += c;
        }
        if(c==k && i == n){
            cout << 0;
            return 0;
        }else{
            k = c;
        }
    }
    int z = s.size();
    int r,l;
    r = 0;
    l = z;
    for(int i = 1;i<=5;i++){
        if(s[r] != s[l]){
            ans++;
        }
        if(r == l + 1 || l == r + 1){
            break;
        }
        r++,l--;
    }
    cout << ans;
    return 0;
}

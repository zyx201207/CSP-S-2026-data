#include <bits/stdc++.h>
using namespace std;
int n,a[200010];
char c[200010];
string s1,s2;
long long ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> a[i] >> c[i];
        for(int j = 1;j <= a[i];j++){
            s1 = s1 + c[i];
            s2 = c[i] + s2;
        }
    }
    for(int i = 0;i < s1.size()/2;i++){
        if(s1[i] != s2[i]){
            s1[i] = s2[i];
            ans++;
        }
    }
    cout << ans;
    return 0;
}

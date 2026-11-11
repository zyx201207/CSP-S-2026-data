#include <bits/stdc++.h>
using namespace std;
long long n,ans;
string a;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n;
    while(n--){
        int x;
        string y;
        cin >> x >> y;
        for(int i=1;i<=x;i++) a += y;
    }
    long long len = a.size();
    for(int i=0;i<len/2;i++){
        if(a[i] != a[len - i - 1]) ans++;
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

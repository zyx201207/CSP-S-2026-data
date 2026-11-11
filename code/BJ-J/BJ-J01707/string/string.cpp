#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+10;
int n;
char a[N];
int cnt=0;
int ans;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    int c=0;
    char b;
    for (int i=1;i<=n;i++){
        cin >> c >> b;
        for (int j=1;j<=c;j++) a[++cnt]=b;
    }
    // for (int i=1;i<=(cnt+1)/2;i++) cout << a[i] << " " << a[cnt+1-i] << endl;
    for (int i=1;i<=(cnt+1)/2;i++){
        if (a[i]!=a[cnt-i+1]) ans++;
    }
    cout << ans;
    return 0;
}
/*
aabbc
Trick||Treat!
*/
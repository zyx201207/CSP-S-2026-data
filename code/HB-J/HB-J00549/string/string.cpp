#include <bits/stdc++.h>
using namespace std;
const int maxn=2e6+5;
int n,a[maxn],ans;
char b[maxn];
string x,y;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for (int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=a[i];j++){
            x+=b[i];
        }
    }
    for (int i=x.length()-1;i>=0;i--){
        y+=x[i];
    }
    if (x==y){
        cout << 0;
        return 0;
    }
    if (b[n]!=b[1]){
        ans+=a[n];
    }
    if (a[n]!=a[1]){
        if (a[n]>a[1]){
            ans+=a[n]-a[1];
        }
        else{
            ans+=a[1]-a[n];
        }
    }
    cout << ans;
    return 0;
}

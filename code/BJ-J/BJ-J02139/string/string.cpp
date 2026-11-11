#include <bits/stdc++.h>
using namespace std;

long long n,b[1000000],sizx=0,ans=0;
string a[1000000];
string x;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> b[i] >> a[i];
        sizx+=b[i];
        for(int j=1;j<=b[i];j++){
            x+=a[i];
        }
    }
    for(int i=0;i<=sizx/2-1;i++){
        if(x[i]==x[sizx-i]){
            continue;
        }
        else{
            ans++;
        }
    }
    cout << ans;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int a[200005],s[200005];
    int n,cnt=0;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            cin >> a[j];
            s+=a[j];

        }
    }
    if(a[i]!=s[i]){
    cnt++;
    }
    cout << cnt;
    return 0;
}

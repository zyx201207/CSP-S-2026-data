#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    int n,m,a;
    cin >> n >> m;
    int s[1005];
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }
    for(int i=2;i<=n;i++){
       if(min(s[i],s[i-1])){
           a=min(s[i],s[i-1]);
       }
    }
    cout << a;
    return 0;


}

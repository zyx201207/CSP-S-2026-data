#include<bits/stdc++.h>
using namespace std;
const int MAXn = 2e5+10;
int n,a[MAXn],ans;
char c[MAXn],cn;
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i = 1 ; i <= n ; i++){
        cin>>a[i]>>c[i];
        cn = c[i];
    }
    for(int i = 1 ; i <= n ; i++){
        if(c[i] == cn) ans = 0;
    }
    cout<<ans;
    return 0;
}

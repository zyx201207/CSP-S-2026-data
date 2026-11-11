#include<bits/stdc++.h>
using namespace std;

int mint(){

    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    int n,i;
    cin >> n;
    cin >> i;
    if(i>0){
        n+1;
    }else{
        n-1;
    }
    cout << n << " " << i;

return 0;
}

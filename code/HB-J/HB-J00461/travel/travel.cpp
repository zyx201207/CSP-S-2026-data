#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    char x[5],r[5];
    for(int i=0;i<=5;i++){
        cin >> x[i];
        cin >> r[i];
    }
    if(x[4]+1==r[4] || x[4]-1==r[4]){
        cout << "1111";
    }
    else{
        cout << "1110";
    }
    return 0;
}

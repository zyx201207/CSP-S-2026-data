#include<bits/stdc++.h>
using namespace std;
int c1,c2,s1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    if(c1 == c2){
        cout << 1;
    }else if(c1 != c2 || s1 != s2){
        cout << 0;
    }else if(s1/s2 == 0){
        cout << 1;
    }
    return 0;
}

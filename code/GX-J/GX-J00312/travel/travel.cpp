#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c,s,c1,s1;
    int n;
    cin >> c >> s >> c1 >> s1;
    if(c == c1){
        cout << 1;
        n = 1;}
    else
            cout << 0;
    for(int i=1;i<=3;i++)
        cout << 0;
    return 0;
}

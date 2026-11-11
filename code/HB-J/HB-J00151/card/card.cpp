#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    int a,b,c,big=0;
    cin >> a >> b;
    for(int i=1;i<=a;i++){
        cin >> c;
        if(c>=big){
            big=c;
        }
    }
    cout << a << b << big;
}

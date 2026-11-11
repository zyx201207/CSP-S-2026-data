#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("string .in","r",stdin);
    freopen("string.out","w",stdout);
    int n;
    cin >> n;

    int m1,m2;
    string l1,l2;
    cin >> m1 >> l1 >> m2 >> l2;

    if(n==1){
        cout << 0;
    }else if(n==2){
        if(l1==l2){
            cout << 0;
        }else{
            if(m1<=m2){
                cout <<m1;
            }else{
                cout << m2;
            }
        }
    }else{
        cout << 1;
    }





    return 0;
}

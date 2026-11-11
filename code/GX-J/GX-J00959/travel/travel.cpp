#include <bits/stdc++.h>
using namespace std;
string c,s,ctwo,stwo;
int a;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c >> ctwo >> s >> stwo;
    if(c== s)cout << 1;
    else{
        cout << 0;
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    if(ctwo[0] == stwo[0] && ctwo[1] == stwo[1])cout << 1;
    else{
        cout << 0;
        cout << 0;
        cout << 0;
        return 0;
    }
    if((ctwo[2] == 'A' && stwo[2]!= 'D' && stwo[2]!= 'F')||(ctwo[2] == 'B' && stwo[2]!='D' && stwo[2]!='F')||(ctwo[2] == 'C' && stwo[2]!='D' && stwo[2]!='F')||(ctwo[2] == 'D' && stwo[2]!='A' && stwo[2]!='B' && stwo[2]!='C')||(ctwo[2] == 'F' && stwo[2]!='A' && stwo[2]!='B' && stwo[2]!= 'C'))
        a = 1;
    if(a==1)
        cout << a;
    else cout << 0;
    if(a==1 && abs(ctwo[2]-stwo[2])==1) cout << 1;
    else cout << 0;
    return 0;
}

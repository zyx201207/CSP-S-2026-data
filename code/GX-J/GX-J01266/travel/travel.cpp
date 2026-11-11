#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,c1,s2,c2;
    cin>>s1>>c1>>s2>>c2;
    int cc=4;
    if(s1==s2) {
        cout<<1;cc--;
        if(c1[0]==c2[0] and c1[1]==c2[1]){
            cout<<1;cc--;
            if((c1[2]<='C' and c2[2]<='C') or (c1[2]>'C' and c2[2]>'C')){
                cout<<1;cc--;
                if(c1[2]-c2[2] == 1 or c2[2]-c1[2]==1){
                        cout<<1;cc--;
                }
            }
        }
    }
    for(int i=1;i<=cc;i++) cout<<0;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a,aa,b,bb;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>aa>>b>>bb;
    string pa=aa.substr(0,2),pb=bb.substr(0,2);
    if(a==b){
        cout<<"1";
        if(pa==pb){
            cout<<"1";
            if((aa[2]<='C'&&bb[2]<='C')||((aa[2]>'C'&&aa[2]<='E'&&bb[2]>'C'&&bb[2]<='E'))){
                cout<<"1";
                if(aa[2]+1==bb[2]||bb[2]+1==aa[1]){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
//CCF,I want CSP-J 300pts,please! CSP-S 150+pts,please!

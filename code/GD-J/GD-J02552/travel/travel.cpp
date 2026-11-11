#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<'1';
        string a1=s1.substr(0,2),a2 = s2.substr(0,2);
        if(a1==a2){
            cout<<'1';
            char b1 = s1[2],b2 = s2[2];
            if((b1>='A'&&b1<='C'&&b2>='A'&&b2<='C')||(b1>='D'&&b1<='F'&&b2>='D'&&b2<='F')){
                cout<<'1';
                if(abs(b2-b2)==1&&(b2!='C'&&b1!='D')||(b2!='D'&&b1!='C'))cout<<1;
                else cout<<0;
            }
            else cout<<"00";
        }
        else{
            cout<<"000";
        }
    }
    else cout<<"0000";
    return 0;
}

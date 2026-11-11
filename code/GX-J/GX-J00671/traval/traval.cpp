#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    cin>>c1>>s1>>c2>>s2;
    int a1=(s1[0]-'0')*10+s1[1],a2=(s2[0]-'0')*10+s2[1];
    char z1=s1[2],z2=s2[2];
    if(c1==c2){
        cout<<1;
        if(a1==a2){
            cout<<1;
            if((z1<='C'&&z1>='A'&&z1>='A'&&z2<='C')||(z1<='F'&&z1>='D'&&z1>='D'&&z2<='F')){
                cout<<1;
                if((z1+1==z2&&z1!='C')||(z1-1==z2&&z1!='D'))
                    cout<<1;
                else   cout<<0;
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}

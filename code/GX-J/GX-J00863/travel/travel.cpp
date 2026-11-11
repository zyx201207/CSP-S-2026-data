#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
    }else if(c1==c2){
        string a=s1.substr(0,2);
        string b=s2.substr(0,2);
        //cout<<a;
        if(a!=b){
            cout<<"1000";
        }else if(a==b){
            char k1=s1[2];
            char k2=s2[2];
            if((k1<='C'&&k2>'C')||(k1>='D'&&k2<'D')){
                cout<<"1100";
            }else if((k1<='C'&&k2<='C')||(k1>='D'&&k2>='D')){
                if(abs(k1-k2)!=1){
                    cout<<"1110";
                }else if(abs(k1-k2)==1){
                    cout<<"1111";
                }
            }
        }
    }
    return 0;
}

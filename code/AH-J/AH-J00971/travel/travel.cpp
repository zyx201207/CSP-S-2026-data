#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a1,a2,b1,b2;
    cin>>a1>>a2>>b1>>b2;
    if(a1==b1){
        string x=a2.substr(0,2);
        string y=b2.substr(0,2);
        if(x==y){
            if(a2[2]<='C'&&b2[2]<='C'||a2[2]>='D'&&b2[2]>='D'){
                if(a2[2]<='C'){
                    if(a2[2]=='A'&&b2[2]=='C'||a2[2]=='C'&&b2[2]=='A'){
                        cout<<"1110";
                    }else{
                        cout<<"1111";
                    }
                }else{
                    cout<<"1111";
                }
            }else{
                cout<<"1100";
            }
        }else{
            cout<<"1000";
        }
    }else{
        cout<<"0000";
    }
return 0;
}

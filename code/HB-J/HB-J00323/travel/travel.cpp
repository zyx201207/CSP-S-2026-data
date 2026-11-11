#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a=0,b=0,c=0,d=0;
    char s,z;
    cin>>a>>b>>s>>c>>d>>z;
    if(a==c){
        cout<<'1';
        if(b==d){
            cout<<'1';
            if(s<='C'&&z<='C'||s>'C'&&z>'C'){
                cout<<'1';
                if(s-z==1||z-s==1||s=='D'&&z=='F'||s=='F'&&z=='D'){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
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

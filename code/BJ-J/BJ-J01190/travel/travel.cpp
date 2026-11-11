#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("travel.in","r";stdin);
    //freopen("travel.out","w";stdout);
    string a;
    string b;
    string c;
    string d;
    cin>>a>>b>>c>>d;
    if(a==c){
        cout<<"1";
        if(b[0]==d[0] && b[1]==d[1]){
            cout<<"1";
            if(('A'<=b[2] && b[2]<='C') && ('A'<=d[2] && d[2]<='C')){
                cout<<"1";
                if(b[2]==d[2]){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            if(('D'<=b[2] && b[2]<='E') && ('D'<=d[2] && d[2]<='E')){
                cout<<"1";
                if(b[2]==d[2]){
                    cout<<"1";
                }
                else{
                    cout<<"0";
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
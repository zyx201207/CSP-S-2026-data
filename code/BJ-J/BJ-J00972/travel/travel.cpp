#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string a,b,c,d;
    cin>>a>>b>>c>>d;
    if(a!=c){
        cout<<"0000";
        return 0;
    }
    cout<<"1";
    int n=(b[0]-'0')*10+(b[1]-'0');
    int m=(d[0]-'0')*10+(d[1]-'0');
    if(n!=m){
        cout<<"000";
        return 0;
    }
    cout<<"1";
    if((b[2]-'A'<3&&d[2]-'A'<3)||(b[2]-'A'>=3&&d[2]-'A'>=3)){
        cout<<"1";
        if((abs((b[2]-'A')-(d[2]-'A'))==1)||(b[2]=='D'&&d[2]=='F')||(d[2]=='D'&&b[2]=='F')){
            cout<<"1";
            return 0;
        }else{
            cout<<"0";
            return 0;
        }
    }else{
        cout<<"00";
        return 0;
    }
    return 0;
}
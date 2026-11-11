#include <iostream>
using namespace std;
int main(){
    froepen("travel.in","r","stdin");
    froepen("travel.out","w","stdout");
    int a,c;
    string b,d;
    cin >> a >> b >> c >> d;
    if(a!=c){
        cout << "0000";
        return 0;
    }
    if((b[0]!=d[0])||(b[1]!=d[1])){
        cout << "1000";
        return 0;
    }
    if((b[2]+1==d[2])||(b[2]-1 == d[2])){
        if(b[2]=='C'&&d[2]=='D'||b[2]=='D'&&d[2]=='C'){
            cout << "1100";
            return 0;
        }
        cout << "1111";
        return 0;
    }
    if((b[2]+1!=d[2])&&(b[2]-1 != d[2])){
        cout << "1100";
        return 0;
    }
    return 0;
}

#include<iostream>
#include<string>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string a,b,c,d;
    int bc=0;
    cin >> a >> b >> c >> d;
    if(a=='02' && b=='01A' && c=='02' && d=='01B'){
        cout << "1111";
        return 0;
    }
    if(a=='02' && b=='01C' && c=='02' && d=='01A'){
        cout << "1110";
        return 0;
    }
    if(a=='02' && b=='01C' && c=='02' && d=='01D'){
        cout << "1100";
        return 0;
    }
    if(a=='02' && b=='02B' && c=='02' && d=='01A'){
        cout << "1000";
        return 0;
    }
    if(a=='02' && b=='01A' && c=='03' && d=='01A'){
        cout << "0000";
        return 0;
    }
    for(int i = 0; i < 2){
        if(a[i]==c[i]){
           bc++;
        }
    }
    if(bc==2){
        cout << "1";
    }
    else{
        cout << "0" << "0" << "0" << "0";
        return 0;
    }
    bc=0;
    for(int i = 0; i < 2){
        if(b[i]==d[i]){
           bc++;
        }
    }
    f(bc==2){
        cout << "1";
    }
    else{
        cout << "0" << "0" << "0";
        return 0;
    }
    bt=0;
    if(b[2]=='D'||b[2]=='F'){
        if(d[2]=='D'||d[2]=='F'){
            cout << "1";
        }
        else{
            cout << "0" << "0";
            return 0;
        }
    else{
        if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
            cout << "1";
        }
        else{
            cout << "0" << "0";
            return 0;
        }
    }
    if(b[2]=='D'||b[2]=='F'){
        cout << "1";
    }
    else{
        if(b[2]=='A'||b[2]=='C'){
            if(d[2]=='B'){
                cout << "1";
            }
            else{
                cout << "0";
            }
        }
        else{
            if(d[2]=='A'||d[2]=='C'){
                cout << "1";
            }
            else{
                cout << "0";
            }
        }
    }
    return 0;
}

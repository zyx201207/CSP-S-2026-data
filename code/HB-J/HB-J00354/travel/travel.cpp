#include<bits/stdc++.h>
using namespace std;
int a,b,c,d;
char p,q;
bool check(char x, char y){
    if(x=='A'){
        if(y=='B'||y=='C'){
            return true;
        }
    }
    if(x=='B'){
        if(y=='A'||y=='C'){
            return true;
        }
    }
    if(x=='C'){
        if(y=='A'||y=='B'){
            return true;
        }
    }
    if(x=='D'){
        if(y=='F'){
            return true;
        }
    }
    if(x=='F'){
        if(y=='D'){
            return true;
        }
    }
    return false;
}
bool check2(char x,char y){
    if(x=='A' && y=='B'){
        return true;
    }
    if(x=='B' && y=='A'){
        return true;
    }
    if(x=='B' && y=='C'){
        return true;
    }
    if(x=='C' && y=='B'){
        return true;
    }
    if(x=='D' && y=='F'){
        return true;
    }
    if(x=='F' && y=='D'){
        return true;
    }
    return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> a >> c >> p >> b >> d >> q;
    if(a==b){
        cout << 1;
        if(c==d){
            cout << 1;
            if(check(p,q)){
                cout << 1;
                if(check2(p,q)){
                    cout << 1;
                }else{
                    cout << "0";
                }
            }else{
                cout << "00";
            }
        }else{
            cout << "000";
        }
    }else{
        cout << "0000";
    }
    return 0;
}

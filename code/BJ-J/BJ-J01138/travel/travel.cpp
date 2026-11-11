#include<bits/stdc++.h>
using namespace std;

string s1 , s2 , x1 , x2;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin>> s1 >> s2 >> x1 >> x2;
    if( s1 == x1 ){
        cout<< 1;
    }
    else{
        cout<< "0000";
        return 0;
    }
    int s = (s2[0]-'0')*10 + (s2[1]-'0');
    int x = (x2[0]-'0')*10 + (x2[1]-'0');
    if( s == x ){
        cout<< 1;
    }
    else{
        cout<< "000";
        return 0;
    }
    if( s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C' ){
        if( x2[2] == 'A' || x2[2] == 'B' || x2[2] == 'C' ){
            cout<< 1;
        }
        else{
            cout<< "00";
            return 0;
        }
    }
    if( s2[2] == 'D' || s2[2] == 'E' ){
        if( x2[2] == 'D' || x2[2] == 'E' ){
            cout<< 1;
        }
        else{
            cout<< "00";
            return 0;
        }
    }
    if( s2[2] == 'A' ){
        if( x2[2] == 'B' ){
            cout<< 1;
        }
        else{
            cout<< 0;
        }
    }
    else if( s2[2] == 'B' ){
        if( x2[2] == 'A' || x2[2] == 'C' ){
            cout<< 1;
        }
        else  cout<< 0;
    }
    else if( s2[2] == 'C' ){
        if( x2[2] == 'B' ){
            cout<< 1;
        }
        else  cout<< 0;
    }
    else if( s2[2] == 'D' ){
        if( x2[2] == 'E' ){
            cout<< 1;
        }
        else  cout<< 0;
    }
    else{
        if( x2[2] == 'D' ){
            cout<< 1;
        }
        else  cout<< 0;
    }
    return 0;
}

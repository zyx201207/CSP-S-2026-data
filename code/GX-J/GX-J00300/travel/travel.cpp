#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string seat1,seat2,t,m;
    cin >> t >> seat1 >> m >> seat2;

    if(t==m){
        cout << "1";
    }
    else{
        cout << "0";
    }

    if(seat1[0] == seat2[0] && seat1[1] == seat2[1]){
        if(seat1[2]==seat2[2])
            cout << "0";
        else
            cout << "1";
    }
    else{
        cout << "0";
    }

    if(seat1[2] < 'D' && seat2[2] < 'D'){
        if( (seat1[2]=='A') && (seat2[2]=='B') || (seat1[2]=='B') && (seat2[2]=='C') || seat1[2]=='D' && (seat2[2]=='F') ){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    else if(seat1[2] > 'C' && seat2[2] > 'C'){
        if( (seat1[2]=='A') && (seat2[2]=='B') || (seat1[2]=='B') && (seat2[2]=='C') || seat1[2]=='D' && (seat2[2]=='F') ){
            cout << "1";
        }else{
            cout << "0";
        }
    }
    else{
        cout << "0";
    }
    if( (seat1[2]=='A') && (seat2[2]=='B') || (seat1[2]=='B') && (seat2[2]=='C') || seat1[2]=='D' && (seat2[2]=='F') ){
        cout << "1";
    }else{
        cout << "0";
    }


    return 0;
}

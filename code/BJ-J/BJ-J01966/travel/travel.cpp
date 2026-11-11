#include <bits/stdc++.h>
using namespace std ;
int main(){
    freopen("travel.in","r",stdin) ;
    freopen("travel.out","w",stdout) ;
    string x1,x2,y1,y2 ;
    cin >> x1 >> x2 >> y1 >> y2 ;
    for (int i=0 ; i<x1.size() ; i++){
        if (x1[i]!=y1[i]){
            cout << "0000" ;
            return 0 ;
        }
    }
    for (int i=0 ; i<2 ; i++){
        if (x2[i]!=y2[i]){
            cout << "1000" ;
            return 0 ;
        }
    }
    if (((x2[2]=='A' || x2[2]=='B' || x2[2]=='C') && (y2[2]=='A' || y2[2]=='B' || y2[2]=='C')) || ((x2[2]=='D' || x2[2]=='E' ) && (y2[2]=='D' || y2[2]=='E'))){

    }
    else {
        cout << "1100" ;
        return 0 ;
    }
    if (((x2[2]=='A' || x2[2]=='B' || x2[2]=='C') && (y2[2]=='A' || y2[2]=='B' || y2[2]=='C'))){
        if (x2[2]+1==y2[2] || x2[2]-1==y2[2]){
            cout << "1111" ;
            return 0 ;
        }
        else {
            cout << "1110" ;
            return 0 ;
        }
    }
    else {
        if (x2[2]+1==y2[2] || x2[2]-1==y2[2]){
            cout << "1111" ;
            return 0 ;
        }
        else {
            cout << "1110" ;
            return 0 ;
        }
    }
    return 0 ;
}

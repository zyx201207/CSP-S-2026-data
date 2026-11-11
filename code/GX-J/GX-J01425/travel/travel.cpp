#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string c1,c2;
    cin>> c1 >> c2 ;
    string c3,c4;
    cin>> c3 >> c4;
    if(c1==c3){
        cout<< 1;
    }else{
        cout<< 0 << 0 << 0 << 0;
        return 0;
    }
    string c2_line="", c4_line="";
    c2_line +=c2[0];
    c2_line +=c2[1];
    c4_line +=c4[0];
    c4_line +=c4[1];
    char c2_ce = c2[2];
    char c4_ce = c4[2];
    if(c2_line == c4_line){
        cout<< 1;

    }else{
        cout<< 0;

    }
    if(c2_ce <= 'C'&&c2_ce>='A'&&c4_ce<='C'&&c4_ce>='A' && c2_line == c4_line){
        cout<< 1;
        if(c2_ce == c4_ce-1 || c2_ce == c4_ce+1){
            cout<< 1;
        }else{
        cout<< 0;
    }
    }else if(c2_ce <= 'F'&&c2_ce>='D'&&c4_ce<='F'&&c4_ce>='D'&&c2_line == c4_line){
        cout<< 1;
        if(c2_ce == c4_ce-1 || c2_ce == c4_ce+1){
            cout<< 1;
        }else{
            cout<< 0;
        }
    }else{
        cout<< 0 << 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

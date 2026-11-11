#include<bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string xk,xd,yk,yd;
    cin>>xk>>xd>>yk>>yd;
    string s = "";
    if(xk == yk){
        s += '1';
        string dx = "";
        dx += xd[0];
        dx += xd[1];
        string dy = "";
        dy += yd[0];
        dy += yd[1];
        if(dx == dy){
            s += '1';
            if(yd[2] == 'A' || yd[2] == 'B' || yd[2] == 'C'){
                if(xd[2] == 'A' || xd[2] == 'B' || xd[2] == 'C'){
                    s += '1';
                    if((yd[2] == 'A' && xd[2] == 'B') || (yd[2] == 'B' && xd[2] == 'C') || (xd[2] == 'A' && yd[2] == 'B') || (xd[2] == 'B' && yd[2] == 'C')){
                        s += '1';
                    }else{
                        s += '0';
                    }
                }else{
                    s += "00";
                }
            }else{
                if(xd[2] == 'D' || xd[2] == 'F'){
                    s += '1';
                    if((xd[2] == 'D' && yd[2] == 'F') || (yd[2] == 'D' && xd[2] == 'F')){
                        s += '1';
                    }else{
                        s += '0';
                    }
                }else{
                    s += "00";
                }
            }
        }else{
            s += "000";
        }

    }else{
        s += "0000";
    }
    cout<<s;
    return 0;
}
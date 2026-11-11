#include <bits/stdc++.h>
using namespace std;
string rc,rs,xc,xs;
string a;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.ont","w",stdout);
    cin>>rc>>rs>>xc>>xs;
    if(rc==xc){
            a+="1";
        if(rs[0]==xs[0]){
            if(rs[1]==xs[1]){
                a+="1";




                if(rs[2]=='A'){
                    if(xs[2]=='B'){
                        a+="11";
                    }
                    else if(xs[2]=='C'){
                        a+="10";
                    }
                    else{
                        a+="00";
                    }
                }
                if(rs[2]=='B'){
                    if(xs[2]=='A'){
                        a+="11";
                    }
                    else if(xs[2]=='C'){
                        a+="11";
                    }
                    else{
                        a+="00";
                    }
                }
                 if(rs[2]=='C'){
                    if(xs[2]=='B'){
                        a+="11";
                    }
                    else if(xs[2]=='A'){
                        a+="10";
                    }
                    else{
                        a+="00";
                    }
                }
                 if(rs[2]=='D'){
                    if(xs[2]=='F'){
                        a+="11";
                    }
                    else{
                        a+="00";
                    }
                }
                 if(rs[2]=='F'){
                    if(xs[2]=='D'){
                        a+="11";
                    }
                    else{
                        a+="00";
                    }
                }





            }
            else{
                a+="000";
            }
        }
        else{
            a+="000";
        }
    }
    else{
        a+="0000";
    }
    cout<<a;



    return 0;
}

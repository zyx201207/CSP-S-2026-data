#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    string m,n;
    m=b.substr(0,2);
    n=d.substr(0,2);
    if(a==c){
        cout<<"1";
        if(m==n){
            cout<<"1";
            if((b.substr(2,2)=="A" || b.substr(2,2)=="B" || b.substr(2,2)=="C") && (d.substr(2,2)=="A" || d.substr(2,2)=="B" || d.substr(2,2)=="C")){
                cout<<"1";
                if((b.substr(2,2)=="A" && d.substr(2,2)=="B")||(b.substr(2,2)=="B" && d.substr(2,2)=="C")||(b.substr(2,2)=="C" && d.substr(2,2)=="B")||(b.substr(2,2)=="B" && d.substr(2,2)=="A")){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else if((b.substr(2,2)=="D" || b.substr(2,2)=="F") && (d.substr(2,2)=="D" || d.substr(2,2)=="F")){
                cout<<"11";
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
}

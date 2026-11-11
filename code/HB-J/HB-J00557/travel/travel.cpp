#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    string x,y;
    if(c1==c2){
        cout<<"1";
        x=s1.substr(0,2);
        y=s2.substr(0,2);
        if(x==y){
            cout<<"1";
            x=s1.substr(2,1);
            y=s2.substr(2,1);
            if((x=="A"||x=="B"||x=="C")&&(y=="A"||y=="B"||y=="C")){
                cout<<"1";
                if((x=="A"&&y=="B")||(x=="C"&&y=="B")||(y=="A"&&x=="B")||(y=="C"&&x=="B")){
                    cout<<"1";
                }
                else{
                    cout<<"0";
                }
            }
            else if((x=="D"||x=="F")&&(y=="D"||y=="F")){
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
    return 0;
}

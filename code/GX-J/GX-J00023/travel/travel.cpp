#include <bits/stdc++.h>
using namespace std;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string caon,cap,catw,caq;
    cin>>caon>>cap>>catw>>caq;

    for(int i=1;i<=2;i++){
        cin>>caon[i];
    }
    for(int i=1;i<=2;i++){
        cin>>catw[i];
    }
    for(int i=1;i<=3;i++){
        cin>>cap[i];
    }
    for(int i=1;i<=3;i++){
        cin>>caq[i];
    if(caon[i]!=catw[i]){
        cout<<"0000";
        return 0;
    }
    if(caon[i]==catw[i]){
        cout<<"1";
    }
    if(cap[1]==caq[1]&&cap[2]==caq[2]){
        cout<<"1";
    }
        else;{
            cout<<"0";
        }
    if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="A"&&caq[3]=="B"){
        cout<<"1";
    }
        else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="A"&&caq[3]=="C"){
            cout<<"1";
        }
            else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="B"&&caq[3]=="A"){
                cout<<"1";
            }
                else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="B"&&caq[3]=="C"){
                    cout<<"1";
                }
                    else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="E"&&caq[3]=="D"){
                        cout<<"1";
                    }
                        else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="D"&&caq[3]=="E"){
                            cout<<"1";
                        }
                        else;{
                            cout<<"0";
                        }

    if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="A"&&caq[3]=="B"){
        cout<<"1";
    }
        else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="B"&&caq[3]=="A"){
            cout<<"1";
        }
            else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="B"&&caq[3]=="C"){
                cout<<"1";
            }
                else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="C"&&caq[3]=="B"){
                    cout<<"1";
                }
                    else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="D"&&caq[3]=="E"){
                        cout<<"1";
                    }
                        else if(cap[1]==caq[1]&&cap[2]==caq[2]&&cap[3]=="E"&&caq[3]=="D"){
                            cout<<"1";
                        }
                            else;{
                                cout<<"0";
                            }
    return 0;
}

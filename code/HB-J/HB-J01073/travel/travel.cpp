#include<bits/stdc++.h>
#define ll long long
using namespace std;
string fc1,fc2,fs1,fs2,texc1,texc2,numc1,numc2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>fc1>>fs1>>fc2>>fs2;
    if(fc1==fc2){
        cout<<1;
    }
    else{
        cout<<"0000";
        return 0;
    }
    texc1+=fs1[0];
    texc1+=fs1[1];
    texc2+=fs2[0];
    texc2+=fs2[1];
    if(texc1==texc2){
        cout<<1;
    }
    else{
        cout<<"000";
        return 0;
    }
    numc1+=fs1[2];
    numc2+=fs2[2];
    if(numc1=="D"){
        if(numc2=="F"){
            cout<<11;
        }
        else{
            cout<<"00";
        }
    }
    else if(numc1=="F"){
        if(numc2=="D"){
            cout<<11;
        }
        else{
            cout<<"00";
        }
    }
    else if(numc1=="A"){
        if(numc2=="B"){
            cout<<11;
        }
        else if(numc2=="C"){
            cout<<10;
        }
        else{
            cout<<"00";
        }
    }
    else if(numc1=="B"){
        if(numc2=="A"){
            cout<<11;
        }
        else if(numc2=="C"){
            cout<<11;
        }
        else{
            cout<<"00";
        }
    }
    else if(numc1=="C"){
        if(numc2=="B"){
            cout<<11;
        }
        else if(numc2=="A"){
            cout<<10;
        }
        else{
            cout<<0;
            cout<<0;
        }
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int che1,che2,pai1,pai2;
string lie1,lie2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>che1>>pai1>>lie1;
    cin>>che2>>pai2>>lie2;
    if(che1==che2){
        cout<<"1";
        if(pai1==pai2){
            cout<<"1";
            if(lie1=="A"&&lie2=="B"||lie1=="A"&&lie2=="C"||lie1=="B"&&lie2=="C"||
               lie1=="B"&&lie2=="A"||lie1=="C"&&lie2=="A"||lie1=="C"&&lie2=="B"||
               lie1=="D"&&lie2=="F"||lie1=="F"&&lie2=="D"){
                    cout<<"1";
                    if(lie1=="A"&&lie2=="B"||lie1=="B"&&lie2=="C"||
                    lie1=="B"&&lie2=="A"||lie1=="C"&&lie2=="B"||
                    lie1=="D"&&lie2=="F"||lie1=="F"&&lie2=="D"){
                        cout<<"1";
                    }else{
                        cout<<"0";
                    }
               }else{
                   cout<<"00";
               }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}

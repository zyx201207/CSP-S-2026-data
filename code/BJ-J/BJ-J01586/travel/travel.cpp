#include<iostream>
#include<cmath>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int ac=(c1[0]-48)*10+(c1[1]-48),bc=(c2[0]-48)*10+(c2[1]-48);
    int ap=(s1[0]-48)*10+(s1[1]-48),bp=(s2[0]-48)*10+(s2[1]-48);
    int al=s1[2]-64;
    int bl=s2[2]-64;
    if(ac==bc){
        cout<<'1';
        if(ap==bp){
            cout<<'1';
            if(al/4==bl/4){
                cout<<'1';
                if(abs(al-bl)==1){
                    cout<<'1';
                }
                else{
                    cout<<'0';
                }
            }
            else{
                cout<<"00";
            }
        }
        else{
            cout<<"000";
        }
    }
    else{cout<<"0000";}
}

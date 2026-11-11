#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    char a=s1[1];
    char b=s2[1];
    char c,d;
    c=s1[2];
    d=s2[2];
    int m=0;
    if(c1==c2){
        cout<<"1";
        if(a==b){
            cout<<"1";
            if(c<='c'&&d<='c'){
                m=1;

            }
            if(c>='d'&&d>='d'){
                m=1;
            }
            if(m==1){
                    cout<<"1";
                if(abs(c-d)==1){
                    cout<<"1";

                }
                else{
                    cout<<"0";
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
    else{
        cout<<"0000";
        }





}

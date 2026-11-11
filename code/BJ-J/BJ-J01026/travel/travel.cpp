#include<bits/stdc++.h>

using namespace std;
int c1,c2;
string s1,s2;
string s11="00",s12="0",s21="00",s22="0";
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1!=c2){
        cout<<"0000";
        return 0;
    }
    else{
        s11[0]=s1[0];
        s11[1]=s1[1];
        s12[0]=s1[2];
        s21[0]=s2[0];
        s21[1]=s2[1];
        s22[0]=s2[2];
        if(s11==s21){
            if(s12<="C"&&s22<="C"){
                if((s12=="A"&&s22=="B")||(s12=="B"&&s22=="C")||(s12=="B"&&s22=="A")||(s12=="C"&&s22=="B")){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else if(s12>="D"&&s22>="D"){
                if((s12=="D"&&s22=="F")||(s12=="F"&&s22=="D")){
                    cout<<"1111";
                }
                else{
                    cout<<"1110";
                }
            }
            else{
                cout<<"1100";
            }
        }
        else{
            cout<<"1000";
            return 0;
        }
    }
    return 0;
}

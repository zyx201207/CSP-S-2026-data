#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(s1[1]==s2[1]){
            cout<<"1";
            if(s1[2]<=71&&s2[2]<=71){
                cout<<"1";
                    if(s1[2]==69&&s2[2]==70)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==70&&s2[2]==71)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==72&&s2[2]==73)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==70&&s2[2]==69)
                        cout<<"1";
                    else
                        cout<<"0";
                        if(s1[2]==71&&s2[2]==70)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==73&&s2[2]==72)
                        cout<<"1";
                    else
                        cout<<"0";


                }

                else if(s1[2]>71&&s2[2]>71){
                    cout<<"1";
                    if(s1[2]==69&&s2[2]==70)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==70&&s2[2]==71)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==72&&s2[2]==73)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==70&&s2[2]==69)
                        cout<<"1";
                    else
                        cout<<"0";
                        if(s1[2]==71&&s2[2]==70)
                        cout<<"1";
                    else
                        cout<<"0";
                    if(s1[2]==73&&s2[2]==72)
                        cout<<"1";
                    else
                        cout<<"0";




            }
                cout<<"00";

        }
        else
            cout<<"000";
        }
    else
        cout<<"0000";

}

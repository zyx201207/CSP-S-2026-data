#include <iostream>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int ab2,bb2;
    string ab,bb,aa,ba;
    ab2=((ab[0]-'0')*10+ab[1]-'0');
    bb2=((bb[0]-'0')*10+bb[1]-'0');
    string a2,b2;
    a2[0]=ab[3];
    b2[0]=bb[3];
    cin>>aa>>ab>>ba>>bb;
    if(aa==ba){
        cout<<'1';
        if(ab2=bb2){
            cout<<'1';
            if ((a2=="D"&& b2=="F")||(a2=="F"&& b2=="D")){
                cout<<"11";
            }
            else{
                if ((a2=="A"&& b2=="B")||(a2=="A"&& b2=="C")||(a2=="B"&& b2=="C")||(b2=="A"&& a2=="B")||(b2=="A"&& a2=="C")||(b2=="B"&& a2=="C")){
                    if ((a2=="A"&& b2=="B")||(a2=="B"&& b2=="C")||(b2=="A"&& a2=="B")||(b2=="B"&& a2=="C")){
                        cout<<"11";
                    }
                    else{
                        cout<<"10";
                }
            }
                else{
                    cout<<"00";
                }
            }
        }
        else{
            cout<<"000";
        }
    }
    if (aa!=ba){
        cout<<"0000";
    }
    return 0;
}

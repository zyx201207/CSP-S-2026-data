#include<std/c++.h>
using namespace std;
int c1,c2s1_p,s2_p;
string s1,s2,s1_z,s2_z,;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        s1_p=(s1[0]-"0")*10+(s1[1]-"0");
        s2_p=(s2[0]-"0")*10+(s2[1]-"0");
        if(s1_p==s2_p){
            cout<<"1";
            s1_z=s1[2];
            s2_z=s2[2];
            if(((s1_z>="A"&&s1_z<="C")&&(s2_z>="A"&&s2_z<="C"))||((s1_z="D"||s1_z="F")&&(s2_z="D"||s2_z="F"))){
                cout<<"1";
                if(int(s1_z)-int(s2_z)==1||int(s2_z)-int(s1_z)==1) cout<<"1";
                else cout<<"0";
            }
            else cout<<"00";
        }
        else cout<<"000";
    }
    else cout<<"0000";
    return 0;
}
//fang wei @)!#)@@!

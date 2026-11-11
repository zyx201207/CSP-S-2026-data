#include <iostream>
using namespace std;
string c1,s1,c2,s2;
string b1,b2,b3,b4;
int abc1, abc2,de1,de2;
bool flag = 0;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1==c2) b1 = "1";
    else b1 = "0";
    for(int i=0;i<2;i++){
        if(s1[i]!=s2[i]){
            flag = 1;
        }
    }
    if(b1=="1" && flag==0) b2 = "1";
    else b2 = "0";

    if(s1[2] =='A'||s1[2] =='B'||s1[2] == 'C') abc1 = 1;
    if(s2[2] =='A'||s2[2] == 'B'||s2[2] == 'C') abc2 = 1;
    if(s1[2] == 'D' || s1[2] == 'E') de1 = 1;
    if(s2[2] == 'D' || s2[2] == 'E') de2 = 1;

    if(b1=="1" && b2=="1" && abc1==1 && abc2==1){
        b3 = "1";
    }else if(b1=="1" && b2=="1" && de1==1 && de2==1){
        b3 = "1";
    }
    else b3 = "0";

    if(b1=="1" && b2=="1" && b3=="1" && s2[2]-s1[2]==1) b4 = "1";
    else b4 = "0";

    cout << b1 << b2 << b3 << b4;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main(){

freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

string c1,s1,c2,s2,ans;
cin >> c1 >> s1 >> c2 >> s2;

string left="ABC";
string right="DF";

//车厢
if(c1==c2){
    ans+="1";

    //同一排
    if(s1[0]==s2[0]&&s1[1]==s2[1]){
    ans+="1";

        //同一侧
        int s1_lr=0,s2_lr=0;

        for(int i=0;i<3;i++){
            if(s1[2]==left[i]){
                s1_lr=1;
            }
            if(s2[2]==left[i]){
                s2_lr=1;
            }
        }

        if(s1_lr==s2_lr){
            ans+="1";

            if( abs(s1[2]-s2[2])==1 ){
                ans+="1";
            }
            else{
                ans+="0";
            }

        }
        else{
            ans+="00";
        }

    }
    else{
        ans+="000";
    }


}
else{
    ans+="0000";
}







cout << ans;

return 0;
}

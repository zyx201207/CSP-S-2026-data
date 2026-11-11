#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,s3,s4,ans,s5,s6;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    for (int i=0;i<2;i++){
        s3+=s1[i];
        s4+=s2[i];
    }
    s5=s1[2];
    s6=s2[2];
    if (c1==c2){
        ans+="1";
        if (s3==s4){
            ans+="1";
            if (((s5=="A"||s5=="B"||s5=="C")&&(s6=="A"||s6=="B"||s6=="C"))||((s5=="D"||s5=="F")&&(s6=="D"||s6=="F"))){
                ans+="1";
                if ((s5=="D"||s5=="F")||((s5=="A"||s5=="B")&&(s6=="A"||s6=="B"))||((s5=="B"||s5=="C")&&(s6=="B"||s6=="C"))){
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
        ans="0000";
    }
    cout << ans;

    return 0;
}

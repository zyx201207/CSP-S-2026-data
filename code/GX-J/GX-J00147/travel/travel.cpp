#include <bits/stdc++.h>
using namespace std;

int main(){
    frespen("travel.in","r",stdin);
    frespen("travel.out","w",stdout);
    string c1,s1,c2,s2,a,b;
    cin>> c1 >> s1>> c2>>s2;
    a=s1[2];
    b=s2[2];
    int cnt=0;
    if(c1==c2){
        cout<<"1";
        for(int i=0;i<=1;i++){
            if(s1[i]==s2[i]){
                cnt++;
            }
            }
            if(cnt==2){
                cout<<"1";
                if(a== "A" ||a== "B"||a== "C"&&b== "A" ||b== "B"||b== "C"){
                    cout <<"1";
                    if(a[0] == b[0]-1||b[0] == a[0]-1){
                        cout<<"1";

                    }
                    else{
                        cout<<"0";
                        }
                    }


                else if(a== "D" ||a== "F"&&b== "D" ||b== "F"){
                    cout <<"1";
                    cout <<"1";
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
    return 0;
}

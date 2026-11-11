#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    if(s1==s3){
         if(s2[0]==s4[0]&&s2[1]==s4[1]){
            if(s2[2]+1==s4[2]||s2[2]-1==s4[2]||s2[2]+2==s4[2]||s2[2]-2==s4[2]){
                if(s2[2]+1==s4[2]||s2[2]-1==s4[2]){
                cout<<1111;
                }
                else{
                cout<<1110;
                }

            }
            else{
                cout<<1100;

            }

        }
        else{
            cout<<1000;
        }
    }
    else{
        cout<<0000;
        return 0;
    }



    return 0;
}

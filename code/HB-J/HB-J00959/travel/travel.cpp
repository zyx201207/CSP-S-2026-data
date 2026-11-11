#include<bits/stdc++.h>
using namespace std;
string s1,s2,c1,c2;
int a,b;
int main(){

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    if(s1[0]=='0'){
        int a=int(s1[1]);
    }
    else{
        int a=int(s1[0])*10+int(s1[1]);
    }
    if(s2[0]=='0'){
        int b=int(s2[1]);
    }
    else{
        int b=int(s2[0])*10+int(s2[1]);
    }
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
        cout<<"1";
        if(a==b){
            cout<<"1";
            if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C'){
                    cout<<"1";
                    if((s1[2]-s2[2])==1||(s1[2]-s2[2])==-1){
                        cout<<"1";
                    }

                    else{
                        cout<<"0";
                    }

            }
            else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
                        cout<<"11";
                    }
            else{
                cout<<"00";
                return 0;
            }

        }
        else{
            cout<<"000";
            return 0;
        }

    }
    else{
        cout<<"0000";
        return 0;
    }



return 0;

}
